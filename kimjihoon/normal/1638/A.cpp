#include <iostream>
#include <algorithm>
using namespace std;

int a[509];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); 
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n; cin >> n;
		int p = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			if (!p && i != a[i]) p = i;
			else if (p == a[i]) reverse(a + p, a + i + 1);
		}
		for (int i = 1; i <= n; i++)
			cout << a[i] << " ";
		cout << '\n';
	}
	return 0;
}