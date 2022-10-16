#include <iostream>
#include <algorithm>
using namespace std;
int N, T, a, b, c, d;
int arr[200100];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while (T--)
	{
		cin >> N;
		int i;
		for (i = 0; i < N; i++)
		{
			int a;
			cin >> arr[i];
		}
		int st = 0;
		for (i = N - 1; i >= 1; i--)
		{
			if (!st)
			{
				if (arr[i - 1] < arr[i])
					st = 1;
			}
			else
			{
				if (arr[i] < arr[i - 1])
				{
					cout << i << '\n';
					st = 5;
					break;
				}
			}
		}
		if (st < 2)
			cout << 0 << '\n';
	}
}