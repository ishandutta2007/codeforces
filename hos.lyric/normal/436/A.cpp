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
#include <deque>
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>
#include <unordered_set>
#include <unordered_map>

using namespace std;

typedef unsigned uint;
typedef long long Int;
typedef vector<int> vint;
typedef pair<int,int> pint;
#define mp make_pair

template<typename T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<typename T> void chmin(T &t, const T &f) { if (t > f) t = f; }
template<typename T> void chmax(T &t, const T &f) { if (t < f) t = f; }
int in() { int x; scanf("%d", &x); return x; }

int N, X;
int T[2010], H[2010], M[2010];

bool used[2010];

int main() {
	
	
	for (; ~scanf("%d%d", &N, &X); ) {
		for (int i = 0; i < N; ++i) {
			T[i] = in();
			H[i] = in();
			M[i] = in();
		}
		int ans = 0;
		for (int s = 0; s < 2; ++s) {
			int bef = s ^ 1;
			int x = X;
			fill_n(used, N, false);
			int tmp = 0;
			for (; ; ) {
				int im = -1;
				for (int i = 0; i < N; ++i) if (!used[i]) {
					if (bef != T[i] && x >= H[i]) {
						if (!~im || M[im] < M[i]) {
							im = i;
						}
					}
				}
// cout<<s<<" "<<im<<endl;
				if (!~im) {
					break;
				}
				bef = T[im];
				x += M[im];
				used[im] = true;
				tmp += 1;
			}
			chmax(ans, tmp);
		}
		printf("%d\n", ans);
	}
	
	return 0;
}