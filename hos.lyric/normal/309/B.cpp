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

#define MAXN 1000010

char buf[6000010];

int N, R, C;
string S[MAXN];

int A[MAXN];
int ASum[MAXN];
int to[MAXN];

int crt[MAXN], nxt[MAXN];

void solve(int e) {
	int i;
	if (e == 0) {
		for (i = 0; i <= N; ++i) {
			crt[i] = i;
		}
		return;
	}
	solve(e / 2);
	for (i = 0; i <= N; ++i) {
		nxt[i] = crt[crt[i]];
	}
	if (e % 2 != 0) {
		for (i = 0; i <= N; ++i) {
			crt[i] = to[nxt[i]];
		}
	} else {
		for (i = 0; i <= N; ++i) {
			crt[i] = nxt[i];
		}
	}
}

int main() {
	int i, j, r;
	
	for (; ~scanf("%d%d%d", &N, &R, &C); ) {
		for (i = 0; i < N; ++i) {
			scanf("%s", buf);
			S[i] = buf;
		}
		for (i = 0; i < N; ++i) {
			A[i] = S[i].size() + 1;
		}
		for (i = 0; i < N; ++i) {
			ASum[i + 1] = ASum[i] + A[i];
		}
		for (j = 0, i = 0; i <= N; ++i) {
			for (; j <= N && ASum[j] - ASum[i] <= C + 1; ++j);
			--j;
			to[i] = j;
		}
// cout<<"to : ";pv(to,to+N+1);
		solve(R);
// cout<<"crt : ";pv(crt,crt+N+1);
		int opt = -1;
		int im = -1;
		for (i = 0; i <= N; ++i) {
			if (opt < crt[i] - i) {
				opt = crt[i] - i;
				im = i;
			}
		}
		for (r = 0; r < R; ++r) {
			if (im == to[im]) {
				break;
			}
			for (i = im; i < to[im]; ++i) {
				if (i > im) printf(" ");
				printf("%s", S[i].c_str());
			}
			puts("");
			im = to[im];
		}
cerr<<"===="<<endl;
	}
	
	return 0;
}