#include <iostream>
#include <algorithm>
using namespace std;
int N, T, a, b, c, d;
int arr[100];
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
			arr[i + 1] = 0;
		}
		for (i = 0; i < 2 * N; i++)
		{
			int a;
			cin >> a;
			if (arr[a] == 0)
			{
				arr[a] = 1;
				cout << a << ' ';
			}
		}
		cout << '\n';
	}
}