/* 2020. 02. 17. IZ*ONE - Fiesta */

#include<cstdio>
#include<algorithm>
#include<vector>
#define SZ 262144
using namespace std;
int n, m, K, Q[201000], w[201000];
int DA[201000], DB[201000];
vector<int>E[201000];
void BFS(int st, int *d) {
	int i, head = 0, tail = 0;
	for (i = 1; i <= n; i++)d[i] = 1e9;
	d[st] = 0, Q[++tail] = st;
	while (head < tail) {
		int x = Q[++head];
		for (auto &y : E[x]) {
			if (d[y] > d[x] + 1) {
				d[y] = d[x] + 1;
				Q[++tail] = y;
			}
		}
	}
}
int IT[SZ + SZ];
void Put(int a, int b) {
	a += SZ;
	while (a) {
		IT[a] = max(IT[a], b);
		a >>= 1;
	}
}
int Max(int b, int e) {
	b += SZ, e += SZ;
	int r = -1e9;
	while (b <= e) {
		r = max(r, max(IT[b], IT[e]));
		b = (b + 1) >> 1, e = (e - 1) >> 1;
	}
	return r;
}
bool Pos(int d) {
	int i;
	for (i = 0; i < SZ + SZ; i++)IT[i] = -1e9;
	for (i = 0; i < K; i++) {
		int x = w[i];
		if (Max(d - DB[x], SZ-1) >= d - DA[x]) {
			return true;
		}
		Put(DA[x], DB[x]);
	}
	return false;
}
void Solve() {
	int i;
	scanf("%d%d%d", &n, &m, &K);
	for (i = 0; i < K; i++) {
		scanf("%d", &w[i]);
	}
	for (i = 0; i < m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		E[a].push_back(b);
		E[b].push_back(a);
	}
	BFS(1, DA);
	BFS(n, DB);
	int b = 0, e = n + n, r = 0;
	while (b <= e) {
		int mid = (b + e) >> 1;
		if (Pos(mid)) {
			r = mid;
			b=mid+1;
		}
		else e = mid - 1;
	}
	r++;
	printf("%d\n", min(r, DA[n]));
}
int main() {
	int TC = 1;
	while (TC--) {
		Solve();
	}
}