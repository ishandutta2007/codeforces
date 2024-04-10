#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	cin >> T;
	while (T --)
	{
		int n, k;
		cin >> n >> k;
		vector <int> a(n);
		for (int i = 0; i < n; ++ i) cin >> a[i];
		bool can = 0;
		for (int i = 0; i < n; ++ i) if (a[i] == 1)
		{
			can = 1;
			break;
		}
		puts(can ? "YES" : "NO");
	}
	return 0;
}