
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

int tab[100][100];

VII v = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

bool licz(int n, int m, PII pos, VI moves) {
	reverse(ALL(moves));
	
	do {
		if (tab[pos.ST][pos.ND] == '#') return 0;
		if (tab[pos.ST][pos.ND] == 'E') return 1;
		pos.ST += v[moves.back()].ST;
		pos.ND += v[moves.back()].ND;
		moves.pop_back();
	} while (!moves.empty());
	return tab[pos.ST][pos.ND] == 'E';
}

void jebaj() {
	int n, m;
	cin >> n >> m;
	FOR(i, 0, n + 2) FOR(j, 0, m + 2) tab[i][j] = '#';
	REP(i, n) {
		string s;
		cin >> s;
		REP(j, m) tab[i + 1][j + 1] = s[j];
	}
	
	PII pos;
	FOR(i, 1, n) FOR(j, 1, m) if (tab[i][j] == 'S') pos = {i, j};
	
	string moves;
	cin >> moves;
	
	VI vv = {0, 1, 2, 3};
	int res = 0;
	do {
		VI w;
		for (char c : moves) w.push_back(vv[c - '0']);
		res += licz(n, m, pos, w);
	} while (next_permutation(ALL(vv)));
	
	cout << res << "\n";
}

int main() {
	IOSYNC;
	int t;
	t = 1;
	while(t--) jebaj();
	return 0;
}