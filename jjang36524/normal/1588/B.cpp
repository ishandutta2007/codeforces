#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define int long long
signed main()
{
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--)
	{
		int N;
		cin >> N;
		cout << "? " << 1 << ' ' << N << '\n';
		cout.flush();
		int a;
		cin >> a;
		int s = 1;
		int e = N;
		while (s != e)
		{
			int m = (s + e) / 2;
			cout << "? " << 1 << ' ' << m << '\n';
			cout.flush();
			int b;
			cin >> b;
			if (a == b)
				e = m;
			else
				s = m + 1;
		}
		cout << "? " << 1 << ' ' << s - 1 << '\n';
		cout.flush();
		int c;
		cin >> c;
		vector<int>arr;
		arr.push_back(0);
		arr.push_back(0);
		arr.push_back(s);
		arr[1] = s - (a - c);
		int d = a - (a - c) * (a - c + 1) / 2;
		int s2 = 0;
		int e2 = (5LL<<29)-1;
		while (s2 != e2)
		{
			int m = (s2 + e2) / 2;
			if (m * m >= 1 + 8 * d)
				e2 = m;
			else
				s2 = m + 1;
		}
		arr[0] = arr[1] - (1 + s2) / 2;
		cout << "! " << arr[0] << ' ' << arr[1] << ' ' << arr[2] << '\n';
		cout.flush();
	}
}