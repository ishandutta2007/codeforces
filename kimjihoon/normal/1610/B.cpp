#include <iostream>
#include <algorithm>
using namespace std;

int n, a[200009];

bool ps(int l)
{
	int s = 1, e = n;
	while (s < e) {
		if (a[s] == a[e]) {
			s++;
			e--;
		}
		else {
			if (a[s] == l) s++;
			else if (a[e] == l) e--;
			else return false;
		}
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		int p = 1;
		while (p < n - p + 1) {
			if (a[p] != a[n - p + 1])
				break;
			p++;
		}
		if (p >= n - p + 1 || ps(a[p]) || ps(a[n - p + 1]))
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
	}
	return 0;
}