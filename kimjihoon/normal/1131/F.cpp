#include <iostream>
using namespace std;

int ds[200009], s[200009], e[200009], p[200009];

int uf(int n)
{
	if (ds[n] == n) return n;
	return ds[n] = uf(ds[n]);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		ds[i] = s[i] = e[i] = i;
	}
	for (int i = 0; i < n - 1; i++) {
		int a, b; cin >> a >> b;
		int ua = uf(a), ub = uf(b);
		p[e[ua]] = s[ub];
		ds[ub] = ua;
		e[ua] = e[ub];
	}
	int t = s[uf(1)];
	for (int i = 0; i < n; i++) {
		cout << t << " ";
		t = p[t];
	}
	cout << '\n';
	return 0;
}