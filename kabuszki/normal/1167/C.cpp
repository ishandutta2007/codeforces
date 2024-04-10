
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

VI r, s, p;

int Find(int a) {
	if (a == p[a]) return a;
	return p[a] = Find(p[a]);
}

void Union(int a, int b) {
	a = Find(a);
	b = Find(b);
	if (a == b) return;
	if (r[a] < r[b]) {
		p[a] = b;
		s[b] += s[a];
	} else {
		p[b] = a;
		s[a] += s[b];
		if (r[a] == r[b]) r[a]++;
	}
}

void jebaj() {
	int n, m;
	cin >> n >> m;
	r.resize(n + 1);
	p.resize(n + 1);
	FOR(i, 1, n) p[i] = i;
	s = VI(n + 1, 1);
	
	REP(i, m) {
		int a;
		cin >> a;
		if (a == 0) continue;
		int b;
		cin >> b;
		a--;
		REP(j, a) {
			int c;
			cin >> c;
			Union(b, c);
		}
	}
	FOR(i, 1, n) {
		int a = Find(i);
		cout << s[a] << " ";
	}
	cout << "\n";
}

#undef int
int main() {
	IOSYNC;
	int t = 1;
	//cin >> t;
	while(t--) jebaj();
	return 0;
}