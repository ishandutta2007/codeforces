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

const int N=82;

int n,t0,a[N],dp[2][N][N][N*N],ans[N*N];

int calc0(int t0,int t1){
    f(i,1,n+1){
        t0-=(a[i]==0);
        t1-=(a[i]==1);
        if(t0==0) return max(0,t1);
    }
}
int calc1(int t0,int t1){
    f(i,1,n+1){
        t0-=(a[i]==0);
        t1-=(a[i]==1);
        if(t1==0) return max(0,t0);
    }
}
void solve(){
    f(i,0,2) f(j,0,N) f(k,0,N) f(o,0,N*N) dp[i][j][k][o]=-N*N;
    dp[0][0][0][0]=0;
    f(an,0,n){
        int s=an&1;
        f(t,0,min(an,t0)+1){
            int c0=calc0(t+1,an-t);
            int c1=calc1(t,an-t+1);
            f(l,0,t+1)
                f(nb,0,t*(an-t)+1){
                    //cout<<an<<" "<<t<<" "<<l<<" "<<nb<<" "<<dp[s][t][l][nb]<<'\n';
                    if(t<t0){
                        maxm(dp[s^1][t+1][l+1][nb+c0],dp[s][t][l][nb]+t-l);
                    }
                    if(t0<t+n-an){
                        maxm(dp[s^1][t][0][nb+c1],dp[s][t][l][nb]);
                    }
                    dp[s][t][l][nb]=-N*N;
                }
        }
    }
    
    f(l,0,t0+1)
        f(nb,0,N*N)
            maxm(ans[nb],dp[n&1][t0][l][nb]);
}

int main(){
    cin>>n;
    f(i,1,n+1){ gett(a[i]); t0+=(a[i]==0); }
    solve(); 
    f(i,0,n*(n-1)/2+1){
        if(i) maxm(ans[i],ans[i-1]);
        cout<<ans[i]<<" ";
    }
}