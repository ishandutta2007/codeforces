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

const int INF = 1001001001;

int N;
Int S;
int L;
Int A[100010];

int segN;
int seg[400010];

void update(int a, int val) {
	for (a += segN; a; a >>= 1) {
		chmin(seg[a], val);
	}
}

int rangeMin(int a, int b) {
	int ret = INF;
	for (a += segN, b += segN; a <= b; a >>= 1, b >>= 1) {
		if ( a & 1) { chmin(ret, seg[a]); ++a; }
		if (~b & 1) { chmin(ret, seg[b]); --b; }
	}
	return ret;
}

int main() {
	
	
	for (; ~scanf("%d", &N); ) {
		S = in();
		L = in();
		for (int i = 0; i < N; ++i) {
			A[i] = in();
		}
		
		for (segN = 1; segN < N + 5; segN <<= 1);
		fill(seg, seg + segN * 2, INF);
		update(0, 0);
		
		multiset<Int> as;
		for (int i = 0, j = 0; i < N; ++i) {
			as.insert(A[i]);
			for (; *--as.end() - *as.begin() > S; ++j) {
				as.erase(as.find(A[j]));
			}
// cout<<j<<" "<<i+1<<endl;
			assert(j < i + 1);
			const int res = rangeMin(j, i + 1 - L);
			update(i + 1, res + 1);
		}
		const int ans = rangeMin(N, N);
		if (ans >= INF) {
			puts("-1");
		} else {
			printf("%d\n", ans);
		}
	}
	
	return 0;
}