#include <bits/stdc++.h>
using namespace std;
 
const double eps = 1e-9;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef __int128 lll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
const int mn=4e5+10;
mt19937 rng(std::chrono::high_resolution_clock::now().time_since_epoch().count());
auto begin_time=std::chrono::high_resolution_clock::now();
const ll mod=31607;

ll po(ll a,ll b=mod-2){
    ll ans=1;
    for(;b;b>>=1,a*=a,a%=mod)if(b&1)ans*=a,ans%=mod;
    return ans;
}

ll inv[mod];
ll p[21][21],t[21][21];
ll cp[21];
int n;

ll csolve(){
    ll mul=1;
    for(int i=0;i<n;i++)mul*=1-cp[i],mul%=mod;
    return mul;
}

ll lsolve(){
    ll ans=0;
    fill(cp,cp+n,1);
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)cp[j]*=p[i][j],cp[j]%=mod;
    ll mul=1,sgn=1;
    for(int i=0;i<1<<n;i++){
        int dif=i^(i-1);
        for(int d=1;d<=i;d<<=1)if(dif&d){
            sgn*=-1;
            int ind=__builtin_ctz(d);
            if(i&d){
                for(int j=0;j<n;j++){
                    cp[j]*=inv[p[ind][j]],cp[j]%=mod;
                    mul*=p[ind][j],mul%=mod;
                }
            } else{
                for(int j=0;j<n;j++){
                    cp[j]*=p[ind][j],cp[j]%=mod;
                    mul*=inv[p[ind][j]],mul%=mod;
                }
            }
        }
        //cerr<<i<<" "<<mul*16%mod<<" "<<csolve()*16%mod<<endl;
        ans+=mul*csolve()*sgn;
        ans%=mod;
    }
    //cerr<<ans*16%mod<<endl;
    return ans;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    cin>>n;
    for(int i=0;i<mod;i++)inv[i]=po(i);
    for(int i=0;i<n;i++)for(int j=0;j<n;j++){
        cin>>p[i][j];
        p[i][j]=(p[i][j]*inv[10000])%mod;
    }
    ll ans=lsolve();
    //cerr<<lsolve()*16%mod<<endl;
    //cerr<<ans*16%mod<<endl;
    memcpy(t,p,sizeof(t));
    ll mul=1;
    for(int i=0;i<n;i++)mul*=p[i][i],mul%=mod,p[i][i]=1;
    ans-=lsolve()*mul%mod;
    //cerr<<lsolve()*mul*16%mod<<endl;
    //cerr<<ans*16%mod<<endl;
    for(int i=0;i<n;i++)mul*=p[n-1-i][i],mul%=mod,p[n-1-i][i]=1;
    ans+=lsolve()*mul%mod;
    //cerr<<lsolve()*mul*16%mod<<endl;
    //cerr<<ans*16%mod<<endl;
    memcpy(p,t,sizeof(p));
    mul=1;
    for(int i=0;i<n;i++)mul*=p[n-1-i][i],mul%=mod,p[n-1-i][i]=1;
    ans-=lsolve()*mul%mod;
    //cerr<<lsolve()*mul*16%mod<<endl;
    //cerr<<ans*16%mod<<endl;
    ans=1-ans;
    ans%=mod;
    if(ans<0)ans+=mod;
    //cerr<<ans*16%mod;
    printf("%lld\n",ans);
}