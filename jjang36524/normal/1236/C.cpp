#include <iostream>
using namespace std;
int N;
int arr[301][301];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	int i,j;
	int count = 0;
	for (i = N*N-N; i >=0; i-=N)
	{
		for (j = 1; j <= N; j++)
		{
			if (count % 2)
			{
				arr[N-j+1][(N * N - i) / N] = i + j;
			}
			else
			{
				arr[j][(N * N - i) / N] = i + j;
			}
			
		}
		count++;
	}
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}
}