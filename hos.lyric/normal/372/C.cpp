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


pint que[150010], *qb, *qe;
void init() {
	qb = qe = que;
}
void push(int pos, int val) {
// cout<<"push "<<pos<<" "<<val<<endl;
	for (; qb != qe && (qe - 1)->second >= val; --qe);
	*qe++ = mp(pos, val);
}
void pop(int pos) {
// cout<<"pop "<<pos<<endl;
	for (; qb != qe && qb->first <= pos; ++qb);
}
int get() {
	assert(qb != qe);
	return qb->second;
}


int N, M, D;
int A[310];
Int B[310], T[310];

int dp[2][150010], *crt, *nxt;


int main() {
	int i;
	int x, xL, xR;
	
	for (; ~scanf("%d%d%d", &N, &M, &D); ) {
		for (i = 0; i < M; ++i) {
			A[i] = in();
			B[i] = in();
			T[i] = in();
		}
		crt = dp[0];
		nxt = dp[1];
		for (i = 0; i < M; ++i) {
			if (i == 0) {
				for (x = 1; x <= N; ++x) {
					nxt[x] = 0;
				}
			} else {
				int w = (int)min(D * (T[i] - T[i - 1]), (Int)N);
// cout<<"w = "<<w<<endl;
				init();
				xL = xR = 1;
				for (x = 1; x <= N; ++x) {
					for (; xR <= N && xR <= x + w; ++xR) {
						push(xR, crt[xR]);
					}
					for (; xL < x - w; ++xL) {
						pop(xL);
					}
					nxt[x] = get();
				}
			}
			for (x = 1; x <= N; ++x) {
				nxt[x] += abs(x - A[i]);
			}
			swap(crt, nxt);
// pv(crt+1,crt+N+1);
		}
		Int ans = 0;
		ans += accumulate(B, B + M, 0LL);
		ans -= *min_element(crt + 1, crt + N + 1);
		cout << ans << endl;
	}
	
	return 0;
}