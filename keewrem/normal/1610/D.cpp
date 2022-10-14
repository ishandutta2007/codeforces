#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ft front()
#define bk back()
#define pb push_back
#define eb emplace_back
#define pf push_front
#define ps push
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define sz(x) (int)b((x).size())
template<typename T>
using pq = priority_queue<T>;
#define FOR(i,k) for(int i = 0; i < (k); i++)
#define foll(i,k) for(long long i = 0; i < (k); i++)
#define FORr(i,k) for(int i = (k)-1; i >= 0; i--)
#define folr(i,k) for(long long i = (k)-1; i >= 0; i--)
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll MOD =   1000000007;//   998244353;
const int MAXN = 3000010;

ll fexp(ll b, int e){
    ll res = 1;
    for(int i = 0; i<31;i++){
        if(e&(1<<i)){res*=b;res%=MOD;}
        b*=b; b%=MOD;
    }
    return res;
}

// INVERSO MOLTIPLICATIVO

ll inv(ll a){
    return fexp(a,MOD-2);
}

// FATTORIALE / BINOMIALE

ll fact[MAXN],finv[MAXN];
ll bin (ll a, ll b){
    return (((fact[a]*finv[b])%MOD)*finv[a-b])%MOD;
}

void f_init(){
    fact[0]=1;
    for(ll i = 1; i < MAXN; i++)fact[i] = (fact[i-1]*i)%MOD;
    finv[MAXN-1] = inv(fact[MAXN-1]);
    for(ll i = MAXN-1; i > 0; i++)finv[i-1] = (finv[i]*i)%MOD;
}

void solve(){
	int N;
	cin >> N;
	vi v(N);
	for(auto &x: v)cin >> x;
	ll ans = fexp(2,N);
	for(int k = 0; k < 30; k++){
		ll c = 0, cc = 0;
		vi w;
		for(auto x: v)if(x%4 == 2)c++;
		for(auto x: v)if(x%4 == 0) {
			cc++;
			w.pb(x/2);
		}
		v = w;
		if(c > 0)ans += MOD - (fexp(2,c-1)*fexp(2,cc))%MOD;
	}

	cout << (ans-1)%MOD << endl;


	return;
}

int main(){
	int T = 1;
	// cin >> T;
	while(T--)solve();
	return 0;
}