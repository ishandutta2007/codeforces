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

int N, K;
Int A[100010];

Int bs[100010];

int main() {
	char buf[110];
	int i, j;
	Int s;
	
	for (; ~scanf("%d%d", &N, &K); ) {
		for (i = 0; i < N; ++i) {
			scanf("%s", buf);
			for (j = 0; buf[j]; ++j) if (buf[j] == '.') buf[j] = ' ';
			istringstream iss(buf);
			Int a, b, c, d;
			iss >> a >> b >> c >> d;
			A[i] = 0;
			A[i] |= a << 24;
			A[i] |= b << 16;
			A[i] |= c <<  8;
			A[i] |= d <<  0;
		}
// for(i=0;i<N;++i)printf("%08llx\n",A[i]);
		/*
			the subnet mask first has one or more one bits, 
			and then one or more zero bits (overall there are 32 bits). 
		*/
		Int ans = -1;
		for (s = 0xfffffffeLL; s; s &= s - 1) {
			for (i = 0; i < N; ++i) {
				bs[i] = A[i] & s;
			}
			sort(bs, bs + N);
			int cnt = unique(bs, bs + N) - bs;
			if (cnt == K) {
				ans = s;
			}
		}
		if (ans == -1) {
			puts("-1");
		} else {
			cout << 
			((ans >> 24 & 0xff)) << "." << 
			((ans >> 16 & 0xff)) << "." << 
			((ans >>  8 & 0xff)) << "." << 
			((ans >>  0 & 0xff)) << endl;
		}
	}
	
	return 0;
}