
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

VI ans;
const int N = 200005;
VI v[N];
int parent[N], usuniety[N], rozm[N];

void wrzuc_do_ansa(int a) {
	ans.PB(a);
	for (int b : v[a]) {
		if (b != parent[a] && !usuniety[b]) {
			wrzuc_do_ansa(b);
		}
	}
}

void dfs(int a) {
	int ile = 0, usuniete = 0;
	rozm[a] = 1;
	for (int b : v[a]) {
		if (b != parent[a]) {
			parent[b] = a;
			dfs(b);
			rozm[a] += rozm[b];
			if (!usuniety[b] && (rozm[b] % 2 == 0)) {
				ile++;
			}
			usuniete += usuniety[b];
		}
	}
	if (!ile && (SIZE(v[a]) - usuniete) % 2 == 0) {
		wrzuc_do_ansa(a);
		usuniety[a] = true;
		rozm[a] = 0;
	}
}

void jebaj() {
	int n;
	cin >> n;
	REP(i, n) {
		int a;
		cin >> a;
		if (a == 0) continue;
		v[a].PB(i + 1);
		v[i + 1].PB(a);
	}
	dfs(1);
	if (SIZE(ans) == n) {
		cout << "YES\n";
		for (int a : ans) cout << a << "\n";
	} else {
		cout << "NO\n";
	}
	
	
}

int main() {
	IOSYNC;
	int t;
	t = 1;
	while(t--) jebaj();
	return 0;
}