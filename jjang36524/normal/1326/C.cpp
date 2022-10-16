#include <algorithm>
#include <iostream>
#define int long long
using namespace std;
int N, K;
int ord[200100];
int rev[200100];
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> K;
	int i;
	for (i = 0; i < N; i++)
	{
		cin >> ord[i];
		rev[i]=ord[i]>N-K;
	}
	cout << K * (2 * N - K + 1) / 2 << ' ';
	int ans = 1;
	int last = -1;
	for (i = 0; i < N; i++)
	{
		if (rev[i])
		{
			if (last != -1)
				ans = ans * (i - last) % 998244353;
			last = i;
		}
	}
	cout << ans;
}