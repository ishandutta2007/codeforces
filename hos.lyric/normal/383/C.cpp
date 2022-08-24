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

#define MAX 1600010

int N, Q;
int A[MAX];
int m, ptr[MAX], next[MAX], zu[MAX];

int sig[MAX], posL[MAX], posR[MAX];
int usLen, us[MAX];

void dfs(int u, int p, int s) {
	int i, v;
	sig[u] = s;
	posL[u] = usLen;
	us[usLen++] = u;
	for (i = ptr[u]; ~i; i = next[i]) if ((v = zu[i]) != p) {
		dfs(v, u, -s);
	}
	posR[u] = usLen;
	us[usLen++] = u;
}

//*
int segN;
Int seg[MAX];

void rangeAdd(int a, int b, Int val) {
	assert(0 <= a && a <= b && b < segN);
// cout<<"rangeAdd "<<a<<" "<<b<<" "<<val<<endl;
	for (a += segN, b += segN; a <= b; a >>= 1, b >>= 1) {
		if ( a & 1) { seg[a] += val; ++a; }
		if (~b & 1) { seg[b] += val; --b; }
	}
}

Int pointGet(int a) {
	assert(0 <= a && a < segN);
	Int ret = 0;
	for (a += segN; a; a >>= 1) {
		ret += seg[a];
	}
	return ret;
}
//*/


//	[a, b)
int bitN;
Int bit0[MAX], bit1[MAX];
void bitRangeAdd(int a, int b, Int val) {
	int x;
	for (x = max(a, 1); x <= bitN; x += x & -x) bit0[x] -= val * a, bit1[x] += val;
	for (x = max(b, 1); x <= bitN; x += x & -x) bit0[x] += val * b, bit1[x] -= val;
}
Int bitSum(int a) {
	Int sum0 = 0, sum1 = 0;
	int x;
	for (x = a; x > 0; x &= x - 1) sum0 += bit0[x], sum1 += bit1[x];
	return sum0 + sum1 * a;
}


int main() {
	int i, u, v;
	
	for (; ~scanf("%d%d", &N, &Q); ) {
		for (u = 0; u < N; ++u) {
			A[u] = in();
		}
		m = 0;
		memset(ptr, ~0, N * 4);
		for (i = 0; i < N - 1; ++i) {
			u = in() - 1;
			v = in() - 1;
			next[m] = ptr[u]; ptr[u] = m; zu[m] = v; ++m;
			next[m] = ptr[v]; ptr[v] = m; zu[m] = u; ++m;
		}
		usLen = 0;
		dfs(0, -1, +1);
// cout<<"us : ";pv(us,us+usLen);
		//*
		for (segN = 2; segN < usLen; segN <<= 1);
		memset(seg, 0, sizeof(seg));
		//*/
		// bitN = usLen + 5;
		// memset(bit0, 0, sizeof(bit0));
		// memset(bit1, 0, sizeof(bit1));
		for (; Q--; ) {
			switch (in()) {
				case 1: {
					u = in() - 1;
					Int val = in();
					rangeAdd(posL[u], posR[u], val * sig[u]);
					// bitRangeAdd(posL[u], posR[u] + 1, val * sig[u]);
				} break;
				case 2: {
					u = in() - 1;
					Int res = pointGet(posL[u]);
					// Int res = bitSum(posL[u] + 1) - bitSum(posL[u]);
					Int ans = A[u] + res * sig[u];
					cout << ans << endl;
				} break;
				default: assert(0);
			}
		}
break;
	}
	
	return 0;
}