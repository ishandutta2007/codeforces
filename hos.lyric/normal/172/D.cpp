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

#define MAX 10000010
const int LIM = 10000005;

int isnp[MAX];
int as[MAX];
Int asSum[MAX];

int main() {
	int i, j;
	
	for (i = 1; i < LIM; ++i) as[i] = i;
	for (i = 2; i * i < LIM; ++i) if (!isnp[i]) {
		for (j = i * i; j < LIM; j += i) {
			isnp[j] = 1;
			for (; as[j] % (i * i) == 0; as[j] /= (i * i));
		}
	}
	for (i = 1; i < LIM; ++i) {
		asSum[i + 1] = asSum[i] + as[i];
	}
	
	int a, n;
	for (; ~scanf("%d%d", &a, &n); ) {
		Int ans = asSum[a + n] - asSum[a];
		cout << ans << endl;
	}
	
	return 0;
}