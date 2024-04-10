#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--)
	{
		int N;
		cin >> N;
		int i;
		vector<int>a, b;
		for (i = 0; i < N; i++)
		{
			int x;
			cin >> x;
			a.push_back(x);
		}
		for (i = 0; i < N; i++)
		{
			int x;
			cin >> x;
			b.push_back(x);
		}
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		for (i = 0; i < N; i++)
		{
			if (a[i] > b[i] || a[i] + 1 < b[i])
			{
				cout << "NO" << '\n';
				break;
			}
		}
		if (i == N)
			cout << "YES" << '\n';
	}
}