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

#define MAX 200010

int H, M;
int D, E, A[MAX];

void makeLinks() {
	D = __gcd(H, M);
	E = H / D;
	int h = 0;
	int i, j;
	for (i = 0; i < D; ++i) {
		for (j = i; ; ) {
			A[j] = h++;
			j = (j + M) % H;
			if (j == i) break;
		}
	}
// cout<<"D = "<<D<<endl;
// cout<<"A : ";pv(A,A+H);
}

int segN;
int segSum[MAX * 4], segIdx[MAX * 4];

void segPro(int a) {
	segSum[a] = segSum[a << 1] + segSum[a << 1 | 1];
	segIdx[a] = segSum[a << 1] ? segIdx[a << 1] : segIdx[a << 1 | 1];
}
void segInit() {
	for (segN = 1; segN < H; segN <<= 1);
	memset(segSum, 0, sizeof(segSum));
	int a;
	for (a = 0; a < segN; ++a) {
		segSum[segN + a] = 1;
		segIdx[segN + a] = a;
	}
	for (a = segN; --a; ) {
		segPro(a);
	}
}
void segAdd(int a, int val) {
	segSum[segN + a] += val;
	segIdx[segN + a] = segSum[segN + a] ? a : segN;
	for (a += segN, a >>= 1; a; a >>= 1) {
		segPro(a);
	}
}
int segSearch(int a, int b) {
	int ret = segN;
	for (a += segN, b += segN; a <= b; a >>= 1, b >>= 1) {
		if ( a & 1) { chmin(ret, segIdx[a]); ++a; }
		if (~b & 1) { chmin(ret, segIdx[b]); --b; }
	}
	return ret;
}

int main() {
	char typ;
	
	for (; ~scanf("%d%d", &H, &M); ) {
		makeLinks();
		segInit();
// cout<<"segSum : ";pv(segSum+1,segSum+segN*2);
		map<int,int> pos;
		Int ans = 0;
		for (int qry = in(); qry--; ) {
// cout<<ans<<endl;
			scanf(" %c", &typ);
			int id = in();
			if (typ == '+') {
				int x = A[in()];
				int l = x / E * E;
				int r = l + E - 1;
				int i = segSearch(x, r);
				if (i == segN) {
					i = segSearch(l, r);
assert(i<segN);
				}
				int tmp = i - x;
				for (; tmp < 0; tmp += E);
				ans += tmp;
// cout<<x<<" "<<i<<endl;
				segAdd(i, -1);
				pos[id] = i;
			} else {
				int i = pos[id];
				segAdd(i, +1);
			}
		}
		cout << ans << endl;
	}
	
	return 0;
}