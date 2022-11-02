#include <iostream>
#include <algorithm>
using namespace std;

struct edge
{
	int u, v, w;
	bool operator<(const edge &r) const {
		return w < r.w;
	}
};

int qr[100009], qs[100009], ds[100009];
edge eg[100009];

int uf(int n)
{
	if (n == ds[n]) return n;
	return ds[n] = uf(ds[n]);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m, k; cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		ds[i] = i;
	int c = 0;
	for (int i = 0; i < k; i++) {
		cin >> qr[i];
		if (qs[qr[i]] == 0) c++;
		qs[qr[i]] = 1;
	}
	for (int i = 0; i < m; i++) 
		cin >> eg[i].u >> eg[i].v >> eg[i].w;
	sort(eg, eg + m);
	int ans = 0;
	for (int i = 0; i < m; i++) {
		int a = uf(eg[i].u), b = uf(eg[i].v);
		if (a != b) {
			ds[b] = a;
			qs[a] += qs[b];
			if (qs[a] >= c) {
				ans = eg[i].w;
				break;
			}
		}
	}
	for (int i = 0; i < k; i++)
		cout << ans << " ";
	cout << '\n';
	return 0;
}