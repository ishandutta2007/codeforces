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
 
const int N=1e6+99,mod=1e9+7;
 
int n,d[N],t,x;
 
int main(){
    vector<pair<int,int> > ans;
    cin>>n;
    cout<<"? "<<1<<endl;
    f(i,1,n+1){
        cin>>d[i];
        if(d[i]==1) ans.pb(mp(1,i));
    }
    f(i,1,n+1)
        if(d[i]%2==0)
            t++;
    if(t<=(n+1)/2){
        f(i,2,n+1){
            if(d[i]%2==0){
                cout<<"? "<<i<<endl;
                f(j,1,n+1){
                    cin>>x;
                    if(x==1) ans.pb(mp(i,j));
                }
            }
        }
    }
    else{
        ans.clear();
        f(i,2,n+1){
            if(d[i]%2==1){
                cout<<"? "<<i<<endl;
                f(j,1,n+1){
                    cin>>x;
                    if(x==1) ans.pb(mp(i,j));
                }
            }
        }
    }
    cout<<"!"<<endl;
    f(i,0,n-1)
        cout<<ans[i].F<<" "<<ans[i].S<<endl;
}