#include <algorithm>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
const int M = 550;
int n, q, a[N], bel[N], fir[M], sz;
vector<int> S[M];
int qry(int u, int v, int w) {
	int ans = 0;
	if(bel[u] == bel[v]) {
		for(int i = u; i <= v; i ++)
			if(a[i] < w) ans ++;
	} else {
		for(int i = u; i < fir[bel[u] + 1]; i ++)
			if(a[i] < w) ans ++;
		for(int i = fir[bel[v]]; i <= v; i ++)
			if(a[i] < w) ans ++;
		for(int i = bel[u] + 1; i < bel[v]; i ++)
			ans += lower_bound(S[i].begin(), S[i].end(), w) - S[i].begin();
	}
	return ans;
	
}
void replace(vector<int> &S, int x, int y) {
	int i, s = (int) S.size() - 1;
	for(i = 0; i <= s; i ++)
		if(S[i] == x) break ;
	S[i] = y;
	for(; i != 0 && S[i] < S[i - 1]; i --) swap(S[i], S[i - 1]);
	for(; i != s && S[i] > S[i + 1]; i ++) swap(S[i], S[i + 1]);
}
int main() {
	scanf("%d%d", &n, &q); sz = (int) sqrt(n + 0.5);
	for(int i = 1; i <= n; i ++) {
		bel[i] = (i + sz - 1) / sz;
		if(bel[i] != bel[i - 1]) fir[bel[i]] = i;
		S[bel[i]].push_back(a[i] = i);
	}
	ll ans = 0;
	for(int u, v, i = 1; i <= q; i ++) {
		scanf("%d%d", &u, &v);
		if(u > v) swap(u, v);
		if(a[u] > a[v]) ans --;
		if(a[u] < a[v]) ans ++;
		if(v - u - 1 >= 1) {
			int qu = qry(u + 1, v - 1, a[u]), qv = qry(u + 1, v - 1, a[v]);
			ans += (qv - qu) * 2;
		}
		replace(S[bel[u]], a[u], a[v]);
		replace(S[bel[v]], a[v], a[u]);
		swap(a[u], a[v]);
		printf("%I64d\n", ans);
	}
	return 0;
}