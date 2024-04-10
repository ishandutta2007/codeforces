#include <iostream>
using namespace std;
int arr[300100];
int di[300100];
int Q, N, K;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> Q;
	while (Q--)
	{
		cin >> N >> K;
		int i;
		int sum=0;
		memset(di, -1, K*4);
		for (i = 0; i < N; i++)
		{
			cin >> arr[i];
			arr[i] = arr[i] % 2;
			sum = (sum + arr[i]) % 2;
		}
		int j = 0;
		for (i = 0; i < N; i++)
		{
			if (arr[i] && j < K - 1)
			{
				di[j] = i;
				j++;
				sum = (sum + 1) % 2;
			}
		}
		if ((j != K - 1) || (!sum) ||( di[j] == N - 1))
			cout << "NO" << '\n';
		else
		{
			cout << "YES" << '\n';
			int i;
			for (i = 0; i < K - 1; i++)
			{
				cout << di[i] + 1 << ' ';
			}
			cout << N << '\n';
		}
	}
}