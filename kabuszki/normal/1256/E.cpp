
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

const int INF = 1e9 + 1;

void jebaj() {
	int n;
	cin >> n;
	VII v(n);
	REP(i, n) {
		cin >> v[i].ST;
		v[i].ND = i;
	}
	sort(ALL(v));
	vector<VI> dp(n, VI(3, INF));
	FOR(i, 2, n - 1) {
		FOR(j, 3, 5) {
			int ii = i - j + 1;
			if (ii < 0) continue;
			if (ii == 0) dp[i][j - 3] = v[i].ST - v[0].ST;
			else {
				dp[i][j - 3] = v[i].ST - v[ii].ST + *std::min_element(ALL(dp[ii - 1]));
			}
		}
	}
	VI res(n);
	int teams = 0;
	int pos = n - 1;
	while (pos >= 0) {
		FOR(j, 3, 5) {
			if (dp[pos][j - 3] == *std::min_element(ALL(dp[pos]))) {
				teams++;
				FORD(ii, pos, pos - j + 1) res[v[ii].ND] = teams;
				pos = pos - j;
				break;
			}
		}
	}
	cout << *std::min_element(ALL(dp[n - 1])) << " " << teams << "\n";
	REP(i, n) cout << res[i] << " "; cout << "\n";
}


#undef int
int main() {
	IOSYNC;
	int t;
	//cin >> t;
	t = 1;
	while(t--) jebaj();
	return 0;
}


/*
 
*/