#include <bits/stdc++.h>
using namespace std;
#define int long long
int psum[1 << 20][2];
int arr[1 << 20];
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M;
	cin >> N >> M;
	int i;
	for (i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	for (i = 1; i < N; i++)
	{
		psum[i][0] = psum[i - 1][0] + max(arr[i] - arr[i - 1], 0LL);
		psum[N-1-i][1]=psum[N-i][1]+ max(arr[N-1-i] - arr[N-i], 0LL);
	}
	while (M--)
	{
		int a, b;
		cin >> a >> b;
		if (a < b)
		{
			cout << psum[a-1][1] - psum[b-1][1] << '\n';
		}
		else
		{
			cout << -psum[b - 1][0] + psum[a - 1][0] << '\n';
		}
	}
}