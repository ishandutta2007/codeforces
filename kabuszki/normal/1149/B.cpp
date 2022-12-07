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

const int INF = 1000000000;

int dp[252][252][252];

vector<VI> dupa {
	{-1, 0, 0},
	{0, -1, 0},
	{0, 0, -1}
};

void update(int nr, const string& s, const vector<string>& v, const vector<VI>& nast) {
	vector<VI> w(3);
	REP(j, 3) {
		if (nr != j) REP(i, SIZE(v[j])) w[j].PB(i);
		else w[j].PB(SIZE(v[nr]) - 1);
	}
	
	for (int i : w[0]) for(int j : w[1]) for (int k : w[2]) {
		VI pyk({i, j, k});
		dp[pyk[0]][pyk[1]][pyk[2]] = INF;
		FOR(num, 0, 2) if (pyk[num] > 0) if (dp[pyk[0] + dupa[num][0]][pyk[1] + dupa[num][1]][pyk[2] + dupa[num][2]] < SIZE(s))
			dp[pyk[0]][pyk[1]][pyk[2]] = min(dp[pyk[0]][pyk[1]][pyk[2]],
				nast[dp[pyk[0] + dupa[num][0]][pyk[1] + dupa[num][1]][pyk[2] + dupa[num][2]]][v[num][pyk[num]] - 'a']);
	}
	
	dp[0][0][0] = 0;
}

void jebaj() {
	int n, q;
	cin >> n >> q; 
	string s;
	cin >> s;
	s = "#" + s;
	vector<VI> nast(n + 1);
	VI last(26, INF);
	FORD(i, n, 1) {
		nast[i] = last;
		last[s[i] - 'a'] = i;
	}
	nast[0] = last;
	vector<string> v(3, "#");
	
	REP(i, q) {
		char c;
		int id;
		cin >> c >> id;
		id--;
		if (c == '+') {
			cin >> c;
			v[id].PB(c);
			update(id, s, v, nast);
		} else {
			v[id].pop_back();
		}
		cout << (dp[SIZE(v[0]) - 1][SIZE(v[1]) - 1][SIZE(v[2]) - 1] <= SIZE(s) ? "YES\n" : "NO\n");
	}
}

int main() {
	IOSYNC;
	int t;
	t = 1;
	while(t--) jebaj();
	return 0;
}