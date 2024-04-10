#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	int T;
	cin >> T;
	while (T --)
	{
		int n;
		cin >> n;
		vector <int> a(n);
		for (int i = 0; i < n; ++ i) cin >> a[i];
		vector <int> pos(n + 1);
		for (int i = 1; i < n; ++ i)
		{
			if (a[i] < a[i - 1]) pos[a[i - 1]] = i;
		}
		for (int i = 1; i <= n; ++ i) cout << pos[i] + 1 << " ";
		cout << endl;
	}
	return 0;
}