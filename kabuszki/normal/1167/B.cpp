
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
	VI res(7);
	VI v = {4, 8, 15, 16, 23, 42};
	VII w = {{1, 2}, {3, 4}, {1, 3}, {5, 5}};
	VI dupa;
	for (auto p : w) {
		cout << "? " << p.ST << " " << p.ND << endl;
		int a;
		cin >> a;
		dupa.PB(a);
	}
	
	do {
		bool chujoza = false;
		REP(i, 4) {
			auto p = w[i];
			if (v[p.ST - 1] * v[p.ND - 1] != dupa[i]) {
				chujoza = true;
			}
		}
		if (!chujoza) {
			cout << "! ";
			for (int a : v) cout << a << " ";
			cout << endl;
			return;
		}
	} while(next_permutation(ALL(v)));
}

#undef int
int main() {
	//IOSYNC;
	int t = 1;
	//cin >> t;
	while(t--) jebaj();
	return 0;
}