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

namespace SA {
	#define MAXN 100010
	int n;
	char t[MAXN];
	int ki[MAXN], ik[MAXN], is[MAXN], hh;
	bool cmp(const int &a, const int &b) {
		return (a == b) ? 0 : (ik[a] != ik[b]) ? (ik[a] < ik[b]) : (ik[a + hh] < ik[b + hh]);
	}
	void makeSA() {
		n = strlen(t);
		int i;
		for (i = 0; i <= n; ++i) ik[ki[i] = i] = t[i];
		is[0] = is[n] = hh = 0;
		sort(ki, ki + n + 1, cmp);
		for (hh = 1; is[n] != n; hh <<= 1) {
			sort(ki, ki + n + 1, cmp);
			for (i = 0; i < n; ++i) is[i + 1] = is[i] + (cmp(ki[i], ki[i + 1]) ? 1 : 0);
			for (i = 0; i <= n; ++i) ik[ki[i]] = is[i];
		}
	}
	int lcp[MAXN];
	void makeHA() {
		int h = 0, i, j;
		for (i = 0; i < n; ++i) {
			for (j = ki[ik[i] - 1]; t[j + h] == t[i + h]; ++h);
			lcp[ik[i] - 1] = h;
			if (h) --h;
		}
	}
}

const int MO = 1000000007;
const Int BIG = 1001001001001001LL;

int N;
char S[5010];
int dpSum[5010][5010];
int dpMin[5010][5010];
int es[5010];

int lcpMins[5010][5010];

int compare(int len, int a, int b) {
	int ia = SA::ik[a];
	int ib = SA::ik[b];
	int sig = +1;
	if (ia > ib) {
		swap(ia, ib);
		sig *= -1;
	}
	if (lcpMins[ia][ib] >= len) {
		return 0;
	}
	return -sig;
}

int main() {
	
	
	for (; ~scanf("%s", S); ) {
		N = strlen(S);
		copy(S, S + N + 1, SA::t);
		SA::makeSA();
		SA::makeHA();
		for (int i = 0; i < N; ++i) {
			lcpMins[i][i] = N - SA::ki[i];
			for (int j = i; j < N; ++j) {
				lcpMins[i][j + 1] = min(lcpMins[i][j], SA::lcp[j]);
			}
		}
// for(int i=0;i<=N;++i)cout<<i<<" "<<(S+SA::ki[i])<<endl;
// for(int i=0;i<=N;++i)pv(lcpMins[i],lcpMins[i]+N+1);
		//	d[0][0] = 1
		//	e[0][0] = 0
		dpSum[0][0] = 1;
		dpMin[0][0] = 0;
		for (int i = 1; i <= N; ++i) {
			//	d[i][i] = 0
			//	e[i][i] = INF
			dpSum[i][i] = 0;
			dpMin[i][i] = N + 1;
			for (int j = i; j--; ) {
				if (i - j > 1 && S[j] == '0') {
					dpSum[i][j] = dpSum[i][j + 1];
					dpMin[i][j] = dpMin[i][j + 1];
					continue;
				}
				//	[i][j]
				int k = max(j + j - i, 0);
				if (j - k == i - j) {
					if (compare(i - j, k, j) > 0) {
						++k;
					}
				}
				const int d = (k <= i) ? dpSum[j][k] : 0;
				const int e = (k <= i) ? (dpMin[j][k] + 1) : (N + 1);
// cout<<i<<" "<<j<<" : "<<d<<" "<<e<<endl;
				dpSum[i][j] = (dpSum[i][j + 1] + d) % MO;
				dpMin[i][j] = min(dpMin[i][j + 1], e);
				es[j] = e;
			}
		}
		
		Int ans1 = dpSum[N][0];
		ans1 = (ans1 % MO + MO) % MO;
		
// cout<<"es : ";pv(es,es+N);
		Int ans2 = -1;
		pair<Int,int> opt(BIG, N + 1);
		for (int j = 0; j < N; ++j) if (es[j] <= N) {
			Int tmp = 0;
			Int tmpBig = 0;
			for (int k = j; k < N; ++k) {
				tmp = (tmp * 2 + (S[k] - '0')) % MO;
				tmpBig = min(tmpBig * 2 + (S[k] - '0'), BIG);
			}
			tmp = (tmp + es[j]) % MO;
			tmpBig = min(tmpBig + es[j], BIG);
// cout<<tmp<<" "<<tmpBig<<endl;
			if (opt > mp(tmpBig, N - j)) {
				opt = mp(tmpBig, N - j);
				ans2 = tmp;
			}
		}
		
		cout << ans1 << endl;
		cout << ans2 << endl;
	}
	
	return 0;
}