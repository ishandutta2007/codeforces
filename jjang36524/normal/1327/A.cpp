#include <iostream>
#include <algorithm>
#include <vector>
#define int long long
using namespace std;
int T;
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while (T--)
	{
		int N, M;
		cin >> N >> M;
		if ((N - M) % 2 || N < M * M)
			cout << "NO" << '\n';
		else
			cout << "YES" << '\n';
	}
}