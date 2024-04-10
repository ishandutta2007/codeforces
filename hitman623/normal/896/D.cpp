#include <bits/stdc++.h>

#define int         long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;

int expo(int base,int exponent,int mod){
    int ans=1;
    while(exponent!=0){
        if(exponent&1) ans=(1LL*ans*base)%mod;
        base=(1LL*base*base)%mod;
        exponent>>=1;
    }
    return ans%mod;
}
const int N=1000006;
vi primes;
int mod,f[N],inv[N],pows[N][20];
void compute(){
    int cur=mod,phi=mod;
    for(int i=2;i*i<=cur;i++){
        if(cur%i==0){
            primes.pb(i);
            phi=phi/i*(i-1);
            while(cur%i==0) cur/=i;  
        }
    }
    if(cur>1) primes.pb(cur),phi=phi/cur*(cur-1);
    f[0]=1;
    rep(i,1,N){
        cur=i;
        rep(j,0,sz(primes)){
            pows[i][j]=pows[i-1][j];
            while(cur%primes[j]==0) pows[i][j]++,cur/=primes[j];
        }
        f[i]=f[i-1]*cur%mod;
        inv[i-1]=cur;
    }
    inv[N-1]=expo(f[N-1],phi-1,mod);
    for(int i=N-2;i>=0;i--) inv[i]=inv[i]*inv[i+1]%mod;
}
int C(int n,int r){
    if(r<0 or n<r) return 0;
    int res=f[n]*inv[r]%mod*inv[n-r]%mod;
    rep(i,0,sz(primes)) res=res*expo(primes[i],pows[n][i]-pows[r][i]-pows[n-r][i],mod)%mod;
    return res;
}
int n,l,r;
void solve(){
    cin>>n>>mod>>l>>r;
    int P=mod,ans=0;
    compute();
    rep(i,l,n+1) ans=(ans+C(n,i)*(C(i,(i-l)/2)-C(i,(i-r+1)/2-1)+P))%P;
    cout<<ans<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}