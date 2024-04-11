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

const int N=2e5+99,mod=998244353;

int n,ans,add,dp[N],a[N][2];
set<pair<int,int> > S;

int main(){
    cin>>n;
    f(i,1,n+1){
        int u,v,s,x;
        cin>>u>>v>>s;
        Add(ans,u-a[i-1][0]);
        a[i][0]=u,a[i][1]=v;
        S.insert(mp(u,i));
        x=(*S.upper_bound(mp(v,0))).S;
        if(x==i)
            dp[i]=u-v;
        else{
            dp[i]=(1ll*dp[x]+add+u-a[i-1][0]+a[x][0]-v)%mod;
        }
        Add(add,(1ll*dp[i]+u-a[i-1][0])%mod);
        Add(dp[i],mod-add);
        if(s) Add(ans,(dp[i]+add)%mod);
        //f(j,1,i+1) cout<<(dp[j]+add)%mod<<" "; cout<<endl;
    }
    cout<<(ans+1)%mod<<endl;
}