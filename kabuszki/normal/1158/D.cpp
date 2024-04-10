
//Karol Kaszuba

#include <bits/stdc++.h>

using namespace std;

#define int long long

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

void usun(VII& v, PII p) {
	int n = SIZE(v);
	REP(i, n) if (v[i] == p) {
		swap(v[i], v[n - 1]);
		v.pop_back();
		return;
	}
}



VII znajdz(PII x, PII y, VII& v) {
	sort(ALL(v), [&](const PII& a, const PII& b) {
		return (a.ST - y.ST) * (b.ND - y.ND) < (a.ND - y.ND) * (b.ST - y.ST);
	});
	return {v.front(), v.back()};
}

void solve(PII x, PII y, VII& punkty, string& s, VII& res) {
	if (s.empty()) {
		assert(SIZE(punkty) == 1);
		res.PB(punkty.front());
		return;
	}
	VII chuj = znajdz(x, y, punkty);
	PII z = (s.back() == 'L' ? chuj[1] : chuj[0]);

	res.PB(z);
	usun(punkty, z);
	s.pop_back();
	solve(y, z, punkty, s, res);
		
}

void jebaj() {
	int n;
	cin >> n;
	VII v(n);
	map<PII, int> mapka;
	REP(i, n) {
		cin >> v[i].ST >> v[i].ND;
		mapka[v[i]] = i + 1;
	}
	string s;
	cin >> s;
	reverse(ALL(s));
	s = s + "L";	
	PII x = {-1000000002, -1000000002}, y = {-1000000001, -1000000002};
	VII res;
	solve(x, y, v, s, res);
	for (auto p : res) cout << mapka[p] << " ";
	cout << "\n";
}


#undef int
int main() {
	IOSYNC;
	int t;
	t = 1;
	while(t--) jebaj();
	return 0;
}