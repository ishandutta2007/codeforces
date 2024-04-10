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

const Int MO = 1000000007;
const int LIM = 100005;

vint divs[100010];

void prepare() {
	int i, j;
	for (i = 1; i < LIM; ++i) {
		for (j = i; j < LIM; j += i) {
			divs[j].push_back(i);
		}
	}
}

int N;
int A[100010];
int is[100010];

Int power(Int a, int e) {
	Int x = a, y = 1;
	for (; e; e >>= 1, (x *= x) %= MO) if (e & 1) (y *= x) %= MO;
	return y;
}
Int solve(const vint &ds) {
	int m = ds.size();
// cout<<"ds : ";pv(ds.begin(),ds.end());
	int i;
	Int ret = 1;
	for (i = 0; i <= m; ++i) {
		int a = (i == 0) ? N : is[ds[i - 1]];
		int b = (i == m) ? 0 : is[ds[i]];
		(ret *= power(i, a - b))%= MO;
	}
	return ret;
}

int main() {
	int i;
	int x;
	
	prepare();
// for(x=1;x<=10;++x){cout<<"divs[x] : ";pv(divs[x].begin(),divs[x].end());}
	
	for (; ~scanf("%d", &N); ) {
		for (i = 0; i < N; ++i) {
			A[i] = in();
		}
		memset(is, 0, sizeof(is));
		for (i = 0; i < N; ++i) {
			++is[A[i]];
		}
		for (x = LIM; x >= 0; --x) {
			is[x] += is[x + 1];
		}
// cout<<"is : ";pv(is,is+10);
		Int ans = 0;
		for (x = 1; x < LIM; ++x) {
			vint ds = divs[x];
			(ans += solve(ds)) %= MO;
			ds.pop_back();
			(ans -= solve(ds)) %= MO;
		}
		ans = (ans % MO + MO) % MO;
		cout << ans << endl;
	}
	
	return 0;
}