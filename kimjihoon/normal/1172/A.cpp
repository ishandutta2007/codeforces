#include <iostream>
#include <algorithm>
using namespace std;

int r[200009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);	
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		r[a] = 0;
	}
	for (int i = 0; i < n; i++) {
		int b; cin >> b;
		r[b] = i + 1;
	}
	int c = 1;
	for (int i = 1; i < n; i++) {
		if (r[i] + 1 == r[i + 1]) c++;
		else break;
	}
	if (r[c] != n) c = 0;
	for (int i = c + 1; i <= n; i++) {
		if (r[i] > i - c - 1) {
			c = 0;
			break;
		}
	}
	int ans = 0;
	for (int i = c + 1; i <= n; i++)
		ans = max(ans, r[i] + n - i + 1);
	cout << ans << '\n';
	return 0;
}