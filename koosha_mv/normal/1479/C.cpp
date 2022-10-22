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
 
const int n=23;
 
int l,r,ans;
vector<pair<int,pair<int,int> > > e;
 
int main(){
    cout<<"YES"<<endl;
    cin>>l>>r;
    if(l==1) l++,e.pb(mp(1,mp(1,n)));
    f(i,2,n+1)
        f(j,i+1,n+1)
            e.pb(mp((1<<(max(n-j-1,0))),mp(i,j)));
    f(i,2,n){
        if(l+(1<<(n-i-1))<=r+1){
            e.pb(mp(l-1,mp(1,i)));
            l+=(1<<(n-i-1));
        }
    }
    cout<<n<<endl;
    cout<<e.size()<<endl;
    f(i,0,e.size()){
        cout<<e[i].S.F<<" "<<e[i].S.S<<" "<<e[i].F<<endl;
    }
}