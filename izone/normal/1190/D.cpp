#include<cstdio>
#include<algorithm>
#include<vector>
#define N_ 201000
using namespace std;
struct point {
	int x, y;
}w[N_];
int X[N_], Y[N_], n;
vector<int>G[N_];
int vis[N_];
int BIT[N_];
void Add(int a, int b) {
	while (a <= n) {
		BIT[a] += b;
		a += (a&-a);
	}
}
int Sum(int a) {
	int r = 0;
	while (a) {
		r += BIT[a];
		a -= (a&-a);
	}
	return r;
}
long long Get(int a) {
	return 1ll * a*(a + 1) / 2;
}
int main() {
	int i, j;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d%d", &w[i].x, &w[i].y);
		X[i] = w[i].x;
		Y[i] = w[i].y;
	}
	sort(X + 1, X + n + 1);
	sort(Y + 1, Y + n + 1);
	for (i = 1; i <= n; i++) {
		w[i].x = lower_bound(X + 1, X + n + 1, w[i].x) - X;
		w[i].y = lower_bound(Y + 1, Y + n + 1, w[i].y) - Y;
		G[w[i].y].push_back(w[i].x);
	}
	int s = 0;
	long long res = 0;
	for (i = n; i >= 1; i--) {
		if (G[i].empty())continue;
		sort(G[i].begin(), G[i].end());
		int c = 0;
		for (auto &x : G[i]) {
			if (!vis[x])c++;
		}
		long long t = Get(s + c);
		vector<int>T;

		int sz = G[i].size();
		for (j = 1; j < sz; j++) {
			t -= Get(Sum(G[i][j] - 1) - Sum(G[i][j - 1]));
		}
		t -= Get(Sum(G[i][0] - 1));
		t -= Get(s - Sum(G[i].back()));
		res += t;
		s += c;
		for (auto &x : G[i]) {
			if (!vis[x]) {
				vis[x] = 1;
				Add(x, 1);
			}
		}
	}
	printf("%lld\n", res);
}