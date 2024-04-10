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

		int ans = min(N-1, M) * (min(M, N-1) + 1) / 2;
		ans += !!(M >= N);
		cout << ans << '\n';
	}
}