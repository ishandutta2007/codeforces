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
    for(ll i = MAXN-1; i > 0; i--)finv[i-1] = (finv[i]*i)%MOD;
}


ll kek[MAXN][3]; //somma di tutti chist uguali mod 3

void solve(){
	ll N; cin >> N;
	kek[0][1] = kek[0][0] = kek[0][2] = N;
	kek[1][0] = (N*(N+1)/2*3)%MOD;
	kek[1][1] = (kek[1][0] - N + MOD)%MOD;
	kek[1][2] = (kek[1][1] - N + MOD)%MOD;
	ll kk = inv(3);
	for(int i = 1; i <= 3*N; i++){
		ll tot = bin(3*N+1,i+1);
		kek[i][1] = ((tot+3*MOD-2*kek[i-1][1]-kek[i-1][2])%MOD*kk)%MOD;
		kek[i][2] = (kek[i][1] + kek[i-1][1])%MOD;
		kek[i][0] = (kek[i][2] + kek[i-1][2])%MOD;
	}

	int q; cin >> q; ll a;
	while(q--){
		cin >> a;
		cout << kek[a][0] << endl;
	}
	return;
}

int main(){
	f_init();
    cin.tie(0);
    ios_base::sync_with_stdio(NULL);
    int T = 1;

//    cin >> T;

    while(T--){
        solve();
    }
}