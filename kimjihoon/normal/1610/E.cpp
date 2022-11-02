#include <iostream>
#include <algorithm>
using namespace std;

int a[200009], p[33];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n; cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			a[i] *= -1;
		}
		reverse(a + 1, a + n + 1);
		for (int i = 0; i <= 32; i++)
			p[i] = 1;
		int ans = 1;
		for (int i = 2; i <= n; i++) {
			int l = 1, c = 2;
			for (int j = 0; j <= 32; j++) {
				if (a[l] == a[i]) {
					c += i - l - 1;
					break;
				}
				while (p[j] < i && (p[j] <= l || a[p[j]] * 2 < a[l] + a[i]))
					p[j]++;
				if (p[j] >= i) {
					p[j]--;
					break;
				}
				c++;
				l = p[j];	
			}
			ans = max(ans, c);
		}
		cout << n - ans << '\n';
	}
	return 0;
}