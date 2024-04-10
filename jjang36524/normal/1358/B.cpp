#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
#define int long long
int T;
vector<int>x;
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while (T--)
	{
		int N;
		cin >> N;
		x.clear();
		int i;
		for (i = 0; i < N; i++)
		{
			int a;
			cin >> a;
			x.push_back(a);
		}
		sort(x.begin(), x.end());
		int a = -1;
		for(i=0;i<N;i++)
		{
			
				if (x[i] <= i + 1)
					a = i;
		}
		cout << a + 2 << '\n';
	}
}