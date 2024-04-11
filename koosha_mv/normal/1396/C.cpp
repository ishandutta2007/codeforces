#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define eror(x) cout<<#x<<'='<<(x)<<endl;
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define All(x) x.begin(),x.end()
#define gett(x) scanf("%d",&x);
#define Add(x,y) x=(x+y)%p
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const ll N=1e6+99,Mx=1e18;

int n,r1,c,r2,r3,d,a[N];
ll ans,res,dp[N][2];

ll calc1(int x){
    return 1ll*x*r1+r3;
}
ll calc2(int x){
    return min(1ll*r2+r1,1ll*r1*(x+2));
}
int main(){
    cin>>n>>r1>>r2>>r3>>d;
    f(i,1,n+1) gett(a[i]);
    dp[0][0]=0;
    dp[0][1]=Mx;
    f(i,1,n+1){
        dp[i][1]=dp[i-1][0]+calc2(a[i])+2ll*d;
        dp[i][0]=min(dp[i-1][1]+calc2(a[i]),dp[i-1][0]+calc1(a[i]));
        minm(dp[i][0],Mx);
        minm(dp[i][1],Mx);
    }
    cout<<min(dp[n][0],min(dp[n][1],dp[n-1][1]-d+calc1(a[n])))+1ll*(n-1)*d;
}