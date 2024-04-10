
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

int dp[5005][5005], tab[5005][5005];


void pro(VI a) {
	int n = SIZE(a);
	
	
	REP(i, n) tab[i][i] = a[i];
	FOR(len, 2, n) {
		FORD(i, n - len, 0) {
			tab[i][i + len - 1] = tab[i][i + len - 2] ^ tab[i + 1][i + len - 1];
		}
	}
	
	
	
	
	REP(i, n) dp[i][i] = a[i];
	FOR(len, 2, n) {
		REP(i, n - len + 1) {
			dp[i][i + len - 1] = max({dp[i][i + len - 2], dp[i + 1][i + len - 1], tab[i][i + len - 1]});
		}
	}
}

void jebaj() {
	int n;
	cin >> n;
	{
		VI a(n);
		REP(i, n) cin >> a[i];
		pro(a);
	}
	int q;
	cin >> q;
	while(q--)
	{
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		cout << dp[a][b] << "\n";
	}
	
}

int main() {
	IOSYNC;
	int t;
	t = 1;
	while(t--) jebaj();
	return 0;
}