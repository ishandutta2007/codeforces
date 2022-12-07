
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
	int n, m;
	cin >> n >> m;
	VI v(n), w(m), used(n);
	REP(i, n) cin >> v[i];
	REP(i, m) cin >> w[i];
	sort(ALL(v));
	sort(ALL(w));
	if (v.back() > w.front()) {
		cout << "-1\n";
		return;
	}
	
	int res = 0;
	for (int a : v) res += (m * a);
	
	for (int a : w) res += (a - v.back());
	if (w.front() != v.back()) {
		res += v.back();
		v.pop_back();
		res -= v.back();
	}
	cout << res << "\n";
	return;
	
	
}

#undef int
int main() {
	IOSYNC;
	int t;
	t = 1;
	while(t--) jebaj();
	return 0;
}