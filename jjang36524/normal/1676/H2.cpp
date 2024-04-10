#include <bits/stdc++.h>
using namespace std;
#define int long long 
int fw[200100];
int N;
void upd(int n, int k)
{
	while (n <= N)
	{
		fw[n] += k;
		n += n & -n;
	}
}
int ge(int n)
{
	int ans = 0;
	while (n)
	{
		ans += fw[n];
		n -= n & -n;
	}
	return ans;
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		cin >> N;
		int i;
		int ans = N * (N - 1) / 2;
		for (i = 1; i <= N; i++)
			fw[i] = 0;
		for (i = 0; i < N; i++)
		{
			int a;
			cin >> a;
			ans -= ge(a - 1);
			upd(a, 1);
		}
		cout << ans << '\n';
	}
}