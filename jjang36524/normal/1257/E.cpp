#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>
using namespace std;
int N1,N2,N3;
int assi[200100];
int arr[200100][3];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N1 >> N2 >> N3;
	int i;
	for (i = 0; i < N1; i++)
	{
		int a;
		cin >> a;
		assi[a] = 1;
	}
	for (i = 0; i < N2; i++)
	{
		int a;
		cin >> a;
		assi[a] = 2;
	}
	for (i = 0; i < N3; i++)
	{
		int a;
		cin >> a;
		assi[a] = 3;
	}
	memset(arr, 100, sizeof(arr));
	arr[0][0] = 0;
	int ans = 1 << 30;
	for (i = 1; i <= N1 + N2 + N3; i++)
	{
		int j;
		for (j = 0; j < 3; j++)
		{
			int isright = assi[i] != (j+1);
			int k;
			for (k = 0; k <= j; k++)
			{
				arr[i][j] = min(arr[i][j], arr[i - 1][k] + isright);
			}
			if (i == N1+N2+N3)
			{
				ans = min(ans, arr[i][j]);
			}
		}
	}
	cout << ans;
}