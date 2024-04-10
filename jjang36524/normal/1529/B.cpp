#include <iostream>
#include <algorithm>
#include <vector>
#define int long long
using namespace std;
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		vector<int>x;
		int N;
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			int a;
			cin >> a;
			x.push_back(a);
		}
		sort(x.begin(), x.end());
		int i;
		int mi = 1LL<<60;
		for (i = 0; i < N; i++)
		{
			if (x[i] > 0)
				break;
			if(i!=N-1)
				mi = min(mi, x[i+1] - x[i]);
		}
		if (i < N && mi >= x[i])
			i++;
		cout << i  << '\n';
	}
}