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
		int i;
		int opopt = 0;
		for (i = 1; i <= N; i++)
		{
			if ((M + i) / (i + 1) + 1 > (M + i - 1) / i)
				break;
		}
		i--;
		opopt = i + (M + i) / (i + 1);
		cout << (opopt <= N ? "YES" : "NO") << '\n';
	}
}