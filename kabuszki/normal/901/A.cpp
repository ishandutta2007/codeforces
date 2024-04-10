
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

void jebaj() {
	int h, n = 0;;
	cin >> h;
	VI v;
	REP(i, h + 1) {
		int a;
		cin >> a;
		v.PB(a);
		n += a;
	}
	VI parent1(n + 1), parent2(n + 1);
	
	int act1 = 1, act2 = 1;
	int nr = 2;
	bool myk = false;
	for (int i = 1; i < SIZE(v); i++) {
		if (v[i] == 1) {
			parent1[nr] = act1;
			parent2[nr] = act2;
			nr++;
			act1++;
			act2++;
		} else {
			if (v[i - 1] != 1 && !myk) {
				myk = true;
				for (int j = 0; j < v[i]; j++) {
					parent1[nr + j] = act1;
				}
				
				act1 = nr + v[i] - 1;
				
				for (int j = 0; j < v[i] - 1; j++) {
					parent2[nr + j] = act2;
				}
				parent2[nr + v[i] - 1] = act2 - 1;
				
				act2 = nr + v[i] - 1;
				
				nr += v[i];
			} else {
				for (int j = 0; j < v[i]; j++) {
					parent1[nr + j] = act1;
					parent2[nr + j] = act2;
				}
				act1 = act2 = nr + v[i] - 1;
				
				nr += v[i];
			}
		}
	}
	if (!myk) {
		cout << "perfect\n";
	} else {
		cout << "ambiguous\n";
		FOR(i, 1, n) cout << parent1[i] << " "; cout << "\n";
		FOR(i, 1, n) cout << parent2[i] << " "; cout << "\n";
	}
}

int main() {
	IOSYNC;
	int t;
	t = 1;
	while(t--) jebaj();
	return 0;
}