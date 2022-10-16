#include <iostream>
#include <algorithm>
#define int long long
using namespace std;
int N,M,T;
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while (T--)
	{
		cin >> N >> M;
		int a, b;
		cin >> a >> b;
		if (min(N, M) < b)
		{
			cout << "No" << '\n';
		}
		else if ((N + M - b) < a)
		{
			cout << "No" << '\n';
		}
		else
			cout << "Yes" << '\n';
	}
}