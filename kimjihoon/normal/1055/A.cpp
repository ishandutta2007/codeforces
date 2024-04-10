#include <iostream>
using namespace std;

int a[1009], b[1009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, s;
	cin >> n >> s;
	for (int i = 1; i <= n; i++) 
		cin >> a[i];
	int mx = 0;
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
		if (a[i] && b[i]) mx = i;
	}
	if (s == 1 || (a[1] && (a[s] || (b[s] && s <= mx))))
		cout << "YES" << '\n';
	else
		cout << "NO" << '\n';
	return 0;
}