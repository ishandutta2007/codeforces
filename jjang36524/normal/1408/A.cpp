#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int arr[101][3];
int val[101];
int main()
{
	int N, M,T;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while (T--)
	{
		cin >> N;
		int i,j;
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < N; j++)
				cin >> arr[j][i];
		}
		val[0] = arr[0][0];
		for (i = 1; i < N-1; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (arr[i][j] != val[i - 1])
				{
					val[i] = arr[i][j];
					break;
				}
			}
		}
		for (j = 0; j < 3; j++)
		{
			if (arr[i][j] != val[i - 1]&&arr[i][j]!=val[0])
			{
				val[i] = arr[i][j];
				break;
			}
		}
		for (i = 0; i < N; i++)
		{
			cout << val[i] << ' ';
		}
		cout << '\n';
	}
}