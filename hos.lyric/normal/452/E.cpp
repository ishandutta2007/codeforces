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

const Int MO = 1000000007;

namespace SA {
	#define MAXN 300010
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

int LA, LB, LC;
Int ans[300010];

int eventsLen;
pint events[300010];

int uf[300010];
Int cnt[300010][3];
Int prodSum;

int root(int u) {
	return (uf[u] < 0) ? u : (uf[u] = root(uf[u]));
}
void conn(int u, int v) {
	u = root(u);
	v = root(v);
	if (u == v) return;
	if (uf[u] > uf[v]) swap(u, v);
	uf[u] += uf[v];
	uf[v] = u;
	prodSum -= cnt[u][0] * cnt[u][1] * cnt[u][2];
	prodSum -= cnt[v][0] * cnt[v][1] * cnt[v][2];
	cnt[u][0] += cnt[v][0];
	cnt[u][1] += cnt[v][1];
	cnt[u][2] += cnt[v][2];
	prodSum += cnt[u][0] * cnt[u][1] * cnt[u][2];
}

int main() {
	using namespace SA;
	
	for (; ~scanf("%s", t); ) {
		LA = strlen(t);
		t[LA] = '0';
		scanf("%s", t + LA + 1);
		LB = strlen(t + LA + 1);
		t[LA + 1 + LB] = '1';
		scanf("%s", t + LA + 1 + LB + 1);
		LC = strlen(t + LA + 1 + LB + 1);
		t[LA + 1 + LB + 1 + LC] = '2';
		t[LA + 1 + LB + 1 + LC + 1] = 0;
		makeSA();
		makeHA();
// for(int i=0;i<=n;++i)cout<<t+ki[i]<<endl;
// cout<<"lcp : ";pv(lcp,lcp+n);
		
		eventsLen = 0;
		for (int i = 0; i < n; ++i) {
			events[eventsLen++] = mp(lcp[i], i);
		}
		sort(events, events + eventsLen);
		reverse(events, events + eventsLen);
		fill(uf, uf + n + 1, -1);
		for (int i = 0; i <= n; ++i) {
			cnt[i][0] = 0;
			cnt[i][1] = 0;
			cnt[i][2] = 0;
			if (0 <= ki[i] && ki[i] < LA) {
				cnt[i][0] = 1;
			} else if (LA + 1 <= ki[i] && ki[i] < LA + 1 + LB) {
				cnt[i][1] = 1;
			} else if (LA + 1 + LB + 1 <= ki[i] && ki[i] < LA + 1 + LB + 1 + LC) {
				cnt[i][2] = 1;
			}
		}
		prodSum = 0;
		for (int h = 0, k = n; k >= 0; --k) {
			for (; h < eventsLen && events[h].first == k; ++h) {
				const int i = events[h].second;
				conn(i, i + 1);
			}
			ans[k] = prodSum;
		}
		
// cout<<"ans : ";pv(ans,ans+n+1);
		const int ansLen = min({ LA, LB, LC });
		for (int k = 1; k <= ansLen; ++k) {
			if (k > 1) printf(" ");
			printf("%d", (int)(ans[k] % MO));
		}
		puts("");
	}
	
	return 0;
}