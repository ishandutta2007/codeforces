#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
const int INF = 0x3f3f3f3f;

#define FOR(i, b, e) for(int i = (b); i < (e); i++)
#define TRAV(x, a) for(auto &x: (a))
#define SZ(x) ((int)(x).size())
#define PB push_back
#define PR pair
#define X first
#define Y second

const int M = 1e6+5;
const int B = 1e6+3;
const ll MOD1 = (ll)1e18 + 3;
const ll MOD2 = (ll)1e18 + 9;

int prime[M];

void prepro(){
	FOR(i, 2, M){
		if(prime[i]) continue;
		prime[i] = i;
		for(ll j = 1ll*i*i; j < M; j += i){
			if(!prime[j]) prime[j] = i;
		}
	}
}

pair<ll, ll> kladz(int n){
	pair<ll, ll> ret;
	while(n > 1){
		int akt = prime[n];
		int ile = 0;
		while(prime[n] == akt){
			n /= akt;
			ile ^= 1;
		}
		if(ile > 0){
			ret.X = ((__int128)ret.X * B + akt) % MOD1;
			ret.Y = ((__int128)ret.Y * B + akt) % MOD2;
		}
	}
	return ret;
}

void solve(){
	int n;
	cin >> n;
	vi vec(n);
	TRAV(x, vec) cin >> x;
	map<pair<ll, ll>, int> ile;
	TRAV(x, vec) ile[kladz(x)]++;
	int maks = 0, poczas = 0;
	TRAV(x, ile){
		maks = max(maks, x.Y);
		if(x.X == make_pair(0ll, 0ll) || x.Y % 2 == 0) poczas += x.Y;
	}
	poczas = max(maks, poczas);
	int q;
	cin >> q;
	FOR(i, 0, q){
		ll a;
		cin >> a;
		cout << (a == 0 ? maks : poczas) << '\n';
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	prepro();
	int tt; cin >> tt;
	FOR(te, 0, tt){
		// cout << "Case #" << te+1 << ": ";
		solve();
	}
	// solve();
	return 0;
}