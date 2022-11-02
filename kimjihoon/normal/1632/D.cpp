#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int a, int b)
{
	if (!b) return a;
	return gcd(b, a % b);
}

int a[200009], ep[200009][21], d[200009], l[200009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	int pl = 1;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		ep[i][0] = a[i];
		for (int j = 0; j < 20; j++)
			ep[i][j + 1] = gcd(ep[i][j], ep[max(i - (1 << j), 0)][j]);
		int p = i, g = a[i];
		for (int j = 20; j >= 0; j--)
			if (p - (1 << j) > 0 && i - (p - (1 << j)) + 1 <= gcd(g, ep[p - 1][j])) {
				g = gcd(g, ep[p - 1][j]);
				p -= (1 << j);
			}
		if (i - p + 1 != g) l[i] = i;
		else l[i] = i - p;
		l[i] = min(l[i], l[i - 1] + 1);
		if (i - l[i] - 1 < 0)
			d[i] = 0;
		else 
			d[i] = d[i - l[i] - 1] + 1;
	}
	for (int i = 1; i <= n; i++)
		cout << d[i] << " ";
	cout << '\n';
	return 0;
}