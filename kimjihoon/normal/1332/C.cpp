#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int ds[200009], c[200009][26];

int uf(int n)
{
	if (ds[n] == n) return n;
	return ds[n] = uf(ds[n]);
}

void mg(int a, int b)
{
	a = uf(a); b = uf(b);
	if (a == b) return;
	ds[b] = a;
	for (int i = 0; i < 26; i++)
		c[a][i] += c[b][i];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n, k; cin >> n >> k;
		string s; cin >> s;
		for (int i = 0; i < n; i++) {
			ds[i] = i;
			for (int j = 0; j < 26; j++)
				c[i][j] = 0;
			c[i][s[i] - 'a'] = 1;
		}
		for (int i = 0; i < n - k; i++)
			mg(i, i + k);
		for (int i = 0; i < n - i - 1; i++)
			mg(i, n - i - 1);
		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (ds[i] != i) continue;
			int s = 0, mx = 0;
			for (int j = 0; j < 26; j++) {
				s += c[i][j];
				mx = max(mx, c[i][j]);
			}
			ans += s - mx;
		}
		cout << ans << '\n';	
	}
	return 0;
}