#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define eror(x) cout<<#x<<'='<<(x)<<endl;
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define Add(x,y) x=(x+y)%mod
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=1e5+99;

int n,t,a[N];
vector<pair<int,pair<int,int> > > ans;

void op(int x,int y,int p){
    a[x]-=x*p;
    a[y]+=x*p;
    ans.pb(mp(x,mp(y,p)));
}

int main(){
    cin>>t;
    while(t--){
        int sum=0;
        ans.clear();
        cin>>n;
        f(i,1,n+1){ gett(a[i]); sum+=a[i]; }
        if(sum%n) cout<<-1<<'\n';
        else{
            sum/=n;
            f(i,2,n+1){
                if(a[i]%i!=0){
                    op(1,i,i-a[i]%i);
                }
                op(i,1,a[i]/i);
            }
            f(i,2,n+1)
                op(1,i,sum);
            cout<<ans.size()<<endl;
            f(i,0,ans.size())
                cout<<ans[i].F<<" "<<ans[i].S.F<<" "<<ans[i].S.S<<endl;
        }
    }
}