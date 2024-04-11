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

const int N=5005,mod=998244353;

int n,C[N][N],dp[N][N],ans[N],fac[N];

void add(int x,int c){
    Add(dp[x+1][c],1ll*dp[x][c]*(c+1)%mod);
    Add(dp[x+1][c+1],1ll*dp[x][c]*(x-c)%mod);
}
int main(){
    cin>>n;
    fac[0]=1;
    f(i,1,N)
        fac[i]=1ll*fac[i-1]*i%mod;
    f(i,0,N){
        C[0][i]=1;
        f(j,1,i+1)
            C[j][i]=(C[j][i-1]+C[j-1][i-1])%mod;
    }
    dp[1][0]=1;
    f(i,1,n+1)
        f(j,0,i)
            add(i,j);
    f(i,1,n+1)
        f(j,1,n+1)
            Add(ans[j],1ll*dp[i][j-1]*C[i][n]%mod*fac[n-i]%mod);
    f(i,1,n+1)
        cout<<ans[i]<<" ";
}