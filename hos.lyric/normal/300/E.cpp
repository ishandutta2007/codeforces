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

const int LIM = 10000005;
int minp[10000010];
int psLen, pids[10000010];
Int ps[1000010];
void prepare() {
	int i, j;
	for (i = 2; i < LIM; ++i) if (!minp[i]) for (j = i; j < LIM; j += i) if (!minp[j]) minp[j] = i;
	for (i = 2; i < LIM; ++i) if (minp[i] == i) { pids[i] = psLen; ps[psLen++] = i; }
// cout<<"minp : ";pv(minp,minp+31);
// cout<<"psLen = "<<psLen<<endl;
// cout<<"ps : ";pv(ps,ps+25);
}

int N;
int A[1000010];
int cnt[10000010];

Int es[1000010];

bool check(Int x) {
	int i;
	for (i = 0; i < psLen; ++i) if (es[i]) {
		Int p = ps[i];
		Int f = 0;
		Int xx;
		for (xx = x; xx /= p; ) {
			f += xx;
		}
		if (f < es[i]) {
			return 0;
		}
	}
	return 1;
}

int main() {
	int i;
	int m, mm;
	
	prepare();
	for (; ~scanf("%d", &N); ) {
		for (i = 0; i < N; ++i) {
			A[i] = in();
		}
// N=1000000;
// for(i=0;i<N;++i)A[i]=10000000-i;
		memset(cnt, 0, sizeof(cnt));
		for (i = 0; i < N; ++i) {
			++cnt[A[i]];
		}
		memset(es, 0, sizeof(es));
		Int now = 0;
		for (m = LIM - 1; m >= 2; --m) {
			now += cnt[m];
			for (mm = m; mm > 1; mm /= minp[mm]) {
				es[pids[minp[mm]]] += now;
			}
		}
// cout<<"es : ";pv(es,es+10);
		Int lo = 0, ho = 11001001001001LL;
		for (; lo + 1 < ho; ) {
			Int mo = (lo + ho) / 2;
			check(mo) ? (ho = mo) : (lo = mo);
		}
		cout << ho << endl;
	}
	
	return 0;
}