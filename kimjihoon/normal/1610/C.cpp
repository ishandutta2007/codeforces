#include <iostream>
#include <algorithm>
using namespace std;

int n, a[200009], b[200009];

bool ps(int l)
{
	int c = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] >= c && b[i] >= l - 1 - c) 
			c++;
		if (c >= l) break;
	}
	if (c >= l) return true;
	else return false;
}

int bs(int s, int e)
{
	int md = (s + e + 1) / 2;
	while (s < e) {
		if (ps(md)) s = md;
		else e = md - 1;
		md = (s + e + 1) / 2;
	}
	return md;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> b[i] >> a[i];
		cout << bs(1, n) << '\n';
	}
	return 0;
}