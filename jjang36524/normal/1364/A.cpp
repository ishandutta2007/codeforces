#include <iostream>
#include <algorithm>
#include <vector>
#define int long long
using namespace std;
int T, N, M, a, b, c, d;
int t[100100];
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		cin >> N >> M;
		int i;
		a = 0;
		for (i = 0; i < N; i++)
		{
			cin >> t[i];
			a += t[i];
		}
		if (a % M)
			cout << N;
		else
		{
			b = -1;
			for (i = 0; i < N; i++)
			{
				if(t[i]%M)
					b = max(b, max(N - i-1 ,i));
			}
			cout << b;
		}
		cout << '\n';
	}
}