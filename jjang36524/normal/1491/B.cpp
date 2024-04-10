#include <iostream>
#include <algorithm>
#include <vector>
#include <stdlib.h>
using namespace std;
int arr[100100];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		int N, u, v;
		cin >> N >> u >> v;
		int i;
		for (i = 0; i < N; i++)
		{
			cin >> arr[i];
		}
		int ans=v+min(u,v);
		for (i = 1; i < N; i++)
		{
			if (abs(arr[i] - arr[i - 1]) > 1)
				ans = 0;
			else if (abs(arr[i] - arr[i - 1]) == 1)
				ans = min(ans, min(u, v));
		}
		cout << ans << '\n';
	}
}