#include <iostream>
#include <algorithm>
using namespace std;

int r[509][509], a[509], d[509];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		r[i][i] = a[i];
	}
	for (int l = 1; l < n; l++)
		for (int i = 1; i <= n; i++)
			for (int j = 0; j < l; j++) 
				if (r[i][i + j] && r[i][i + j] == r[i + j + 1][i + l]) {
					r[i][i + l] = r[i][i + j] + 1;
					break;
				}
	for (int i = 1; i <= n; i++) {
		d[i] = 1000000000;
		for (int j = 0; j < i; j++) 
			if (r[j + 1][i])
				d[i] = min(d[i], d[j] + 1);
	}
	cout << d[n] << '\n';
	return 0;
}