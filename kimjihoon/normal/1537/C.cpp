#include <iostream>
#include <algorithm>
using namespace std;

int a[200009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n; cin >> n;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		sort(a, a + n);
		int t = 0;
		for (int i = 1; i < n - 1; i++)
			if (a[t + 1] - a[t] > a[i + 1] - a[i])
				t = i;
		if (n > 2) t++;
		for (int i = 0; i < n; i++)
			cout << a[(i + t) % n] << " ";
		cout << '\n';
	}
	return 0;	
}