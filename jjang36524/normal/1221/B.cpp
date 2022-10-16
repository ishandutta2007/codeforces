#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	int N;
	cin >> N;
	int i;
	for (i = 0; i < N; i++)
	{
		int j;
		for (j = 0; j < N; j++)
		{
			cout << ((i + j) % 2 ? 'W' : 'B');
		}
		cout << '\n';
	}
}