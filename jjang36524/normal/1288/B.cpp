#include <iostream>
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
		cin >> N >> M;
		int i=0;
		int t = 9;
		while (1)
		{
			if (t > M)
				break;
			t = t * 10 + 9;
			i++;
		}
		cout << N * i << '\n';
	}
}