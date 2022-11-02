#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int ds[300009], sp[300009], em[300009], ans;
vector<int> v[300009];

int uf(int n)
{
	if (n == -1 || ds[n] == n) return n;
	return ds[n] = uf(ds[n]);
}

void mg(int a, int b)
{
	ds[a] = b;
	sp[b] += sp[a];
}

int mc(int a)
{
	a = uf(a); int ea = uf(em[a]);
	if (ea == -1) return 0;
	else return min(sp[a], sp[ea]);
}

void mf(int a, int b)
{
	a = uf(a); b = uf(b);
	if (a == b) return;
	int ea = uf(em[a]), eb = uf(em[b]);
	ans -= mc(a) + mc(b);
	mg(a, b);
	if (ea > eb) swap(ea, eb);
	if (ea != -1) mg(ea, eb);
	if (eb != -1) em[eb] = b;
	em[b] = eb;
	ans += mc(a);
}

void me(int a, int b)
{
	a = uf(a); b = uf(b);
	int ea = uf(em[a]), eb = uf(em[b]);
	if (a == eb || b == ea) return;
	ans -= mc(a) + mc(b);
	if (ea != -1) mg(ea, b);
	if (eb != -1) mg(eb, a);
	em[a] = b; em[b] = a;
	ans += mc(a);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k; cin >> n >> k;
	string s; cin >> s;
	for (int i = 1; i <= k; i++) {
		int c; cin >> c;
		for (int j = 0; j < c; j++) {
			int a; cin >> a;
			v[a].push_back(i);
		}
		ds[i] = i; sp[i] = 1; em[i] = -1;
	}
	ds[k + 1] = k + 1; em[k + 1] = k + 2;
	ds[k + 2] = k + 2; em[k + 2] = k + 1;
	ans = 0;
	for (int i = 1; i <= n; i++) {
		if (v[i].size() == 1) {
			if (s[i - 1] == '0') mf(k + 2, v[i][0]);
			else mf(k + 1, v[i][0]);
		}
		else if (v[i].size() == 2) {
			if (s[i - 1] == '0') me(v[i][0], v[i][1]);
			else mf(v[i][0], v[i][1]);
		}
		cout << ans - mc(k + 1) + sp[uf(k + 2)] << '\n';
	}
	return 0;
}