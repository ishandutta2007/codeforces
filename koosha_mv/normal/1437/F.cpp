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

const int N=5005,lg=32,mod=998244353;

int n,a[N],dp[N][lg];
ll ans;

void p(int x,int y){
    if(dp[x][y]==0 || 1) return ;
    cout<<x<<" "<<y<<" : "<<dp[x][y]<<endl;
}
void read(){
    cin>>n;
	f(i,1,n+1) cin>>a[i];
	sort(a+1,a+n+1);    
	reverse(a+1,a+n+1);
	a[0]=2e9;
}
void solve(){
    dp[0][0]=1;
    f(i,1,n+1){
        f(j,0,i)
            f(k,0,lg){
                if(a[i]*2<=a[j])
                    Add(dp[i][k+1],dp[j][k]);
                dp[j][k]=1ll*dp[j][k]*(i-2+(a[i]*2<=a[j]))%mod;
                p(j,k);
            }
        f(k,0,lg)
            p(i,k);
    }
    f(i,0,n+1) 
        f(k,0,lg)
            Add(ans,dp[i][k]);
    cout<<ans;
}

int main(){
	read();
    solve();
}