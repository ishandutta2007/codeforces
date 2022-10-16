#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int N, M, T;
int arr[30];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while (T--)
	{
		cin >> N;
		int i;
		for (i = 0; i < 30; i++)
			arr[i] = 0;
		for (i = 0; i < N; i++)
		{
			int a;
			cin >> a;
			int j;
			for (j = 0; j < 30; j++)
			{
				if (a & (1 << j))
					arr[j]++;
			}
		}
		for (i = 29; i >= 0; i--)
		{
			if (arr[i] % 2)
			{
				if (arr[i] % 4 == 3 && (N - arr[i]) % 2 == 0)
					cout << "LOSE" << '\n';
				else
					cout << "WIN" << '\n';
				break;
			}
		}
		if (i == -1)
			cout << "DRAW" << '\n';
	}
}