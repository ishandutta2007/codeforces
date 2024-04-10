
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

void jebaj() {

	int n;
	cin >> n;
	VI greens, reds, blues;
	REP(i, n) {
		int a;
		char c;
		cin >> a >> c;
		if (c == 'G') greens.PB(a);
		if (c == 'R') reds.PB(a);
		if (c == 'B') blues.PB(a);
	}
	if (greens.empty()) {
		int res = 0;
		if (!reds.empty()) res += reds.back() - reds.front();
		if (!blues.empty()) res += blues.back() - blues.front();
		cout << res << "\n";
		return;
	}
	
	int res = 0;
	if (!blues.empty() && blues.back() > greens.back()) {
		res += blues.back() - greens.back();
		while (!blues.empty() && blues.back() > greens.back()) 
			blues.pop_back();
	}
	if (!reds.empty() && reds.back() > greens.back()) {
		res += reds.back() - greens.back();
		while (!reds.empty() && reds.back() > greens.back()) 
			reds.pop_back();
	}
	
	reverse(ALL(blues));
	reverse(ALL(reds));
	reverse(ALL(greens));
	
	if (!blues.empty() && blues.back() < greens.back()) {
		res -= blues.back() - greens.back();
		while (!blues.empty() && blues.back() < greens.back()) 
			blues.pop_back();
	}
	if (!reds.empty() && reds.back() < greens.back()) {
		res -= reds.back() - greens.back();
		while (!reds.empty() && reds.back() < greens.back()) 
			reds.pop_back();
	}
	reverse(ALL(blues));
	reverse(ALL(reds));
	reverse(ALL(greens));
	
	vector<pair<VI, VI>> kubelki(SIZE(greens));
	
	for (int r : reds) {
		auto it = lower_bound(ALL(greens), r);
		int kubelek = it - greens.begin();
		kubelek--;
		kubelki[kubelek].first.PB(r);
	}
	for (int b : blues) {
		auto it = lower_bound(ALL(greens), b);
		int kubelek = it - greens.begin();
		kubelek--;
		kubelki[kubelek].second.PB(b);
	}
	
	REP(i, SIZE(greens) - 1) {
		auto& rs = kubelki[i].first;
		auto& bs = kubelki[i].second;
		
		int lewo = greens[i], prawo = greens[i + 1];
		
		int cand = 2 * (prawo - lewo);
		int x = 0;
		REP(j, SIZE(rs) - 1)
			x = min(x, rs[j] - rs[j + 1]);
		if (!rs.empty()) x = min(x, lewo - rs[0]);
		if (!rs.empty()) x = min(x, rs.back() - prawo);
		if (x != 0) x += (prawo - lewo);
		
		int y = 0;
		REP(j, SIZE(bs) - 1)
			y = min(y, bs[j] - bs[j + 1]);
		if (!bs.empty()) y = min(y, lewo - bs[0]);
		if (!bs.empty()) y = min(y, bs.back() - prawo);
		if (y != 0) y += (prawo - lewo);
		
		cand = min(cand, (prawo - lewo) + x + y);
		res += cand;
	}
	cout << res << "\n";
}

#undef int
int main() {
	IOSYNC;
	int t;
	t = 1;
	while(t--) jebaj();
	return 0;
}