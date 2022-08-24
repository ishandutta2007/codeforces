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

int N;
int A[1010];

int main() {
	int i;
	
	for (; ~scanf("%d", &N); ) {
		for (i = 0; i < N; ++i) {
			A[i] = in();
		}
		map<int,int> cnt;
		for (i = 0; i < N; ++i) if (A[i]) {
			++cnt[A[i]];
		}
		int ans = 0;
		for (map<int,int>::iterator it = cnt.begin(); it != cnt.end(); ++it) {
			if (it->second > 2) {
				ans = -1;
				break;
			}
			if (it->second == 2) {
				++ans;
			}
		}
		printf("%d\n", ans);
	}
	
	return 0;
}