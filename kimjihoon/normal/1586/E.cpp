#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int ds[300009], dg[300009];
pair<int, int> qr[300009];
vector<int> v[300009], st;
bool vs[300009];

int uf(int n)
{
	if (n == ds[n]) return n;
	return ds[n] = uf(ds[n]);
}

int tg = 0;
bool ff = false;
void dfs(int n)
{
	vs[n] = true;
	st.push_back(n);
	if (n == tg) {
		ff = true;
		return;
	}
	for (int i = 0; i < v[n].size(); i++) {
		int tn = v[n][i];
		if (vs[tn]) continue;
		dfs(tn);
		if (ff) return;
	}
	st.pop_back();
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++)
		ds[i] = i;
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		int ua = uf(a), ub = uf(b);
		if (ua != ub) {
			ds[ua] = ub;
			v[a].push_back(b); v[b].push_back(a);
		}
	}
	int q; cin >> q;
	for (int i = 0; i < q; i++) {
		int a, b; cin >> a >> b;
		qr[i] = make_pair(a, b);
		dg[a]++; dg[b]++;
	}
	int cp = 0;
	for (int i = 1; i <= n; i++)
		if (dg[i] & 1)
			cp++;
	if (cp) {
		cout << "NO" << '\n';
		cout << cp / 2 << '\n';
		return 0;
	}
	cout << "YES" << '\n';
	for (int i = 0; i < q; i++) {
		int a = qr[i].first, b = qr[i].second;
		for (int pi = 1; pi <= n; pi++)
			vs[pi] = false;
		ff = false;
		tg = b;
		st.clear();
		dfs(a);
		cout << st.size() << '\n';
		for (int pi = 0; pi < st.size(); pi++)
			cout << st[pi] << " ";
		cout << '\n';
	}
	return 0;
}