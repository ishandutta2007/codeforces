#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;
int don[101];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		memset(don, 0, sizeof(don));
		int N;
		vector<int>x;
		cin >> N;
		int i;
		for (i = 0; i < N; i++)
		{
			int a;
			cin >> a;
			x.push_back(a);
		}
		sort(x.begin(), x.end());
		for (i = 0; i < N; i++)
		{
			if (!don[x[i]])
			{
				cout << x[i] << ' ';
				don[x[i]] = 1;
				x[i] = -1;
				
			}
		}
		for (i = 0; i < N; i++)
		{
			if (x[i] >= 0)
				cout << x[i] << ' ';
		}
		cout << '\n';
	}
}