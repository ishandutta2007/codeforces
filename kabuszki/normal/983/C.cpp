
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

VII v;
int n;

const int INF = 1000000000;

unordered_map<int, int> mapka;

int licz(int a1, int a2, int a3, int a4, int current_floor, int next_ziomek) {
	
	VI ple = {a1,a2,a3,a4};
	sort(ALL(ple));
	ple.PB(current_floor);
	
	int hehe = 0;
	REP(i, SIZE(ple)) hehe = (10 * hehe + ple[i]);
	hehe = 2001 * hehe + next_ziomek;
	
	if (mapka.find(hehe) != mapka.end()) return mapka[hehe];
	
	a1 = ple[0];
	a2 = ple[1];
	a3 = ple[2];
	a4 = ple[3];
	
	if (next_ziomek == n && a1 + a2 + a3 + a4 == 0) return 0;
	
	int res = INF;
	if (a1 != 0) {
		res = min(res, abs(a1 - current_floor) + 1 + licz(0, a2,a3,a4,a1, next_ziomek));
	}
	if (a2 != 0 && a2 != a1) {
		res = min(res, abs(a2 - current_floor) + 1 + licz(a1, 0,a3,a4,a2, next_ziomek));
	}
	if (a3 != 0 && a3 != a2) {
		res = min(res,  abs(a3 - current_floor) + 1 + licz(a1, a2,0,a4,a3, next_ziomek));
	}
	if (a4 != 0 && a4 != a3) {
		res = min(res,  abs(a4 - current_floor) + 1 + licz(a1, a2,a3,0,a4, next_ziomek));
	}
	
	if (next_ziomek != n && a1 == 0) {
		res = min(res, abs(current_floor - v[next_ziomek].ST) + 1 + licz(v[next_ziomek].ND, a2, a3, a4, v[next_ziomek].ST, next_ziomek + 1));
	}
	
	mapka[hehe] = res;
	
	return res;
}

void jebaj() {
	cin >> n;
	
	REP(i, n) {
		int a, b;
		cin >> a >> b;
		v.PB({a,b});
	}
	cout << licz(0,0,0,0,1,0) << "\n";
}

int main() {
	IOSYNC;
	int t;
	t = 1;
	while(t--) jebaj();
	return 0;
}