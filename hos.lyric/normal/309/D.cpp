#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>

using namespace std;

typedef unsigned uint;
typedef long long Int;
typedef vector<int> vint;
typedef pair<int,int> pint;
#define mp make_pair

template<class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<class T> void chmin(T &t, T f) { if (t > f) t = f; }
template<class T> void chmax(T &t, T f) { if (t < f) t = f; }
int in() { int x; scanf("%d", &x); return x; }

int N, M;
Int anss[50010];

int main() {
	int a, b;
	
	for (; ~scanf("%d%d", &N, &M); ) {
		++N;
		++M;
		for (a = M; a <= N - M; ++a) {
			if (a * 2 > N) {
				anss[a] = anss[N - a];
				continue;
			}
			anss[a] = 0;
			for (b = M; b <= N - M; ++b) {
				int nmr = (N - a) * (2 * a - b);
				int dnm = a + b;
				int x = (nmr < 0) ? (nmr / dnm) : ((nmr + dnm - 1) / dnm);
// cout<<a<<" "<<b<<" "<<x<<endl;
				if (x <= M) {
					break;
				}
				chmin(x, N - M + 1);
				anss[a] += x - M;
			}
		}
		Int ans = 0;
		for (a = M; a <= N - M; ++a) {
			ans += anss[a];
		}
		ans *= 3;
		cout << ans << endl;
	}
	
	return 0;
}