#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string.h>
#define int long long
using namespace std;
int N,M,T;
int arr[100100];
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while (T--)
	{
		cin >> N;
		int i;
		for (i = 0; i < N; i++)
			cin >> arr[i];
		int ma = arr[0];
		int maxdiff = 0;
		for (i = 0; i < N; i++)
		{
			ma = max(ma, arr[i]);
			maxdiff = max(maxdiff, ma - arr[i]);
		}
		int j;
		for (j = 0; j < 60; j++)
		{
			if ((1LL << j) > maxdiff)
				break;
		}
		cout << j << '\n';
	}
}