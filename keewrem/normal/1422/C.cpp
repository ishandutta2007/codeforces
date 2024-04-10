#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int MAXN = 100010;
const ll MOD = 1000000007;
int T;
ll N;
// FATTORIALE / BINOMIALE
// FASTEXP

ll fexp(ll b, ll e){
    ll res = 1;
    for(int i = 0; i<61;i++){
        if(e&(1LL<<i)){res*=b;res%=MOD;}
        b*=b; b%=MOD;
    }
    return res;
}

// INVERSO MOLTIPLICATIVO

ll inv(ll a){
    return fexp(a,MOD-2);
}

ll k[MAXN];
ll kk[MAXN];
int main(){
    string s;
    cin >> s;
    N = s.size();
    ll ans = 0;
    ll q = 0; ll sos;

    for(ll i = N-1; i >= 0; i--){
        sos = s[i]-'0';
        if(i < N-1)q+=(N-1-i)*fexp(10LL,N-2-i);
        q%=MOD;
        ans+=sos*((q+((i+1)*i/2)%MOD*fexp(10LL,N-i-1))%MOD);
        ans%=MOD;
    }
    cout << ans << "\n";
    return 0;
}