#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int arr[200100];

int ac[200100];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T, N;
	cin >> T;
	while (T--)
	{
		cin >> N;
		int i;
		for (i = 0; i < N; i++)
			cin >> arr[i];
		for (i = 0; i < N; i++)
			arr[i]--;
		for (i = 0; i < N; i++)
			ac[i] = 0;
		int c = 0;
		for (i = 0; i < N; i++)
		{
			if (ac[i])
				continue;
			int n = arr[i];
			int t = 0;
			while (n != i)
			{
				n = arr[n];
				t++;
			}
			t++;
			n = arr[i];
			ac[arr[i]] = t;
			while (n != i)
			{
				n = arr[n];
				ac[n] = t;
			}

		}
		for (i = 0; i < N; i++)
		{
			cout << ac[i] << ' ';
		}
		cout << '\n';
	}
}