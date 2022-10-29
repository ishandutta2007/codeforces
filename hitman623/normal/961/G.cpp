#include <bits/stdc++.h>

#define ll          long long
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
const int M=200006;
int f[M],inv[M];
int expo(int base,int exponent,int mod){
    int ans=1;
    while(exponent!=0){
        if(exponent&1) ans=(1LL*ans*base)%mod;
        base=(1LL*base*base)%mod;
        exponent>>=1;
    }
    return ans%mod;
}
void compute(){
    f[0]=1;
    rep(i,1,M){
        f[i]=(1LL*i*f[i-1])%hell;
    }
    inv[M-1]=expo(f[M-1],hell-2,hell);
    for(int i=M-2;i>=0;i--){
        inv[i]=(1LL*(i+1)*inv[i+1])%hell;
    }
}
int C(int n,int r){
    return (1LL*((1LL*f[n]*inv[r])%hell)*inv[n-r])%hell;
}
int S(int n,int k){
    int ans=0;
    rep(i,0,k+1){
        if(i%2){
            ans=(ans+hell-1LL*C(k,i)*expo(k-i,n,hell)%hell)%hell;
        }
        else{
            ans=(ans+1LL*C(k,i)*expo(k-i,n,hell))%hell;
        }
    }
    return (1LL*ans*inv[k])%hell;
}
void solve(){
    compute();
    int k,n,s=0;
    cin>>n>>k;
    rep(i,0,n){
        int x;
        cin>>x;
        s+=x;
        s%=hell;
    }
    cout<<1LL*s*(S(n,k)+1LL*(n-1)*S(n-1,k)%hell)%hell<<endl;
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