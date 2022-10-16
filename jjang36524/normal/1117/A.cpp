#include <iostream>
#include <algorithm>
using namespace std;
#define int long long
int arr[100100];
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	int i;
	int ma = 0;
	for (i = 0; i < N; i++)
	{
		cin >> arr[i];
		ma = max(ma, arr[i]);
	}
	int ans = 0;
	int c = 0;
	for (i = 0; i < N; i++)
	{
		if (arr[i] == ma)
		{
			c++;
		}
		else
			c = 0;
		ans = max(ans, c);
	}
	cout << ans;
}