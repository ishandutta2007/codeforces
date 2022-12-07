
//Karol Kaszuba

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;
typedef double D;
typedef long double LD;
typedef vector<PII> VII;
typedef unordered_set<int> USI;
typedef unordered_set<LL> USLL;

#define FOR(i,x,y) for(auto i=(x);i<=(y);++i)
#define REP(i,x) FOR(i,0,(x)-1)
#define FORD(i,x,y) for(auto i=(x);i>=(y);--i)
#define VAR(i,c) __typeof(c) i=(c)
#define FORE(i,c) for(VAR(i,(c).begin());i!=(c).end();++i)
#define SIZE(c) (int)((c).size())
#define ALL(c) (c).begin(),(c).end()
#define PB push_back
#define EB emplace_back
#define IN insert
#define ER erase
#define MP make_pair
#define ST first
#define ND second
#define IOSYNC ios_base::sync_with_stdio(0)
#define FREOPEN(f) freopen(f, "r", stdin),freopen(f, "w", stdout)

const int N = 100009;
const LL P = 238969, MOD = 1453243241;

int ans[N];
LL pot[N], rev_pot[N], H[N];

unordered_map<int, pair<PII, VI>> mapka;

int qpot(LL a, int b, int mod) {
	LL res = 1;
	while(b) {
		if (b % 2) res = (res * a) % mod;
		a = (a * a) % mod;
		b /=2;
	}
	return res;
}

void prepro(const string& s) {
	pot[0] = 1;
	FOR(i,0, SIZE(s) + 1) pot[i + 1] = (pot[i] * P) % MOD;
	rev_pot[0] = 1;
	rev_pot[1] = qpot(P, MOD - 2, MOD);
	FOR(i, 1, SIZE(s) + 1) rev_pot[i + 1] = (rev_pot[i] * rev_pot[1]) % MOD;
	REP(i, SIZE(s)) H[i] = pot[i] * s[i];
	FOR(i, 1, SIZE(s) - 1) H[i] = (H[i - 1] + H[i]) % MOD;
}


int hasz(const string& s) {
	LL res = 0;
	REP(i, SIZE(s)) res = (res + pot[i] * s[i]) % MOD;
	return res;
}

int get_hasz(int pocz, int kon) {
	LL a = H[kon];
	if (pocz > 0) a -= H[pocz - 1];
	if (a < 0) a += MOD;
	a *= rev_pot[pocz];
	a %= MOD;
	return a;
}

void myk(const string& s, const vector<pair<int, pair<int, string>>>& v) {
	int len = SIZE(v.front().second.second);
	
	for(const auto& x : v) {
		auto h = hasz(x.second.second);
		ans[x.first] = -1;
		mapka[h] = {{x.second.first, x.first}, VI()};
	}
	
	REP(i, SIZE(s) - len + 1) {
		auto h = get_hasz(i, i + len -1);
		if (mapka.find(h) != mapka.end()) {
			mapka[h].second.PB(i);
		}
	}
	
	for(const auto& iiiv : mapka) {
		const auto& iiv = iiiv.second;
		int iw = iiv.first.first;
		int ind = iiv.first.second;
		ans[ind] = 1000000;
		REP(i, SIZE(iiv.second) - iw + 1) 
			ans[ind] = min(ans[ind], iiv.second[i + iw - 1] -iiv.second[i] + len);
		if (ans[ind] == 1000000) ans[ind] = -1;
	}
	mapka.clear();
}

void jebaj() {
	string s;
	cin >> s;
	prepro(s);
	int n;
	cin >> n;
	
	vector<vector<pair<int, pair<int, string>>>> ple(SIZE(s) + 1);
	
	REP(i, n) {
		int k;
		string t;
		cin >> k >> t;
		if (SIZE(t) > SIZE(s)) ans[i] = -1;
		else ple[SIZE(t)].PB({i, {k, t}});
	}
	
	FOR(i, 1, SIZE(s)) if (!ple[i].empty()) myk(s, ple[i]);
	REP(i, n) cout << ans[i] << "\n";
}

int main() {
	IOSYNC;
	cin.tie(0);
	int t;
	t = 1;
	while(t--) jebaj();
	return 0;
}