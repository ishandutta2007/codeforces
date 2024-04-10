#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int k[300009], c[300009];

bool ps(int pi)
{
	for (int i = 0; i < pi; i++) {
		if (k[n - pi + i] < i + 1) return false;
	}
	return true;
}

int bs(int s, int e)
{
	int md = (s + e + 1) / 2;
	while (s < e) {
		md = (s + e + 1) / 2;
		if (ps(md)) s = md;
		else e = md - 1;
	}
	md = (s + e + 1) / 2;
	return md;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		cin >> n >> m;
		long long ans = 0;
		for (int i = 0; i < n; i++) 
			cin >> k[i];
		sort(k, k + n); 
		for (int i = 0; i < m; i++) 
			cin >> c[i];
		for (int i = 0; i < n; i++)
			ans += c[k[i] - 1];
		sort(c, c + m);
		int pi = bs(0, m);
		long long s = ans;
		for (int i = 0; i < pi; i++) {
			s += c[i] - c[k[n - i - 1] - 1];
			ans = min(ans, s);
		}
		cout << ans << '\n';
	}
	return 0;
}