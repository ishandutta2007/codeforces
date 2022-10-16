#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <vector>
using namespace std;
#define int long long
int N, M, T;
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while (T--)
	{
		cin >> N;
		int i;
		for (i = 0; i < N; i++)
		{
			int a;
				cin >> a; 
				a = abs(a);
				if (i % 2)
					a *= -1;
				cout << a << ' ';
		}
		cout << '\n';
	}
}