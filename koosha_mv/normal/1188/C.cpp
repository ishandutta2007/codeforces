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
#define Add(x,y) x=(x+y)%mod;
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=1005,Mx=1e5+10,mod=998244353;

int n,k,ans,a[N],c[N*N],dp[N][N];

void solve(int x){
    dp[0][0]=1;
    f(i,1,n+1)
        f(j,0,k+1){
            dp[i][j]=dp[i-1][j];
            if(j) Add(dp[i][j],dp[c[max(a[i]-x,0)]][j-1]);
        }
}

int main(){
    cin>>n>>k;
    f(i,1,n+1){ gett(a[i]); a[i]++; }
    
    sort(a+1,a+1+n);
    f(i,1,n+1)
        c[a[i]]=i;
    f(i,1,Mx)
        maxm(c[i],c[i-1]);

    f(i,1,Mx/(k-1)+1){
        solve(i);
        Add(ans,dp[n][k]);
    }
    cout<<ans;
}