#include <iostream>
using namespace std;
int N,M;
char arr[200100];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N>>M;
	int bigger = 0;
	int i;
	int sum = 0;
	for (i = 0; i < N; i++)
		cin >> arr[i];
	for (i = 0; i < M; i++)
		sum += arr[i] - '0';
	for (i = M; i < N; i++)
	{
		if (arr[i] > arr[i % M])
		{
			bigger = 1;
			break;

		}
		if (arr[i] < arr[i % M])
		{
			bigger = -1;
			break;
		}
	}
		if (bigger==1)
		{
			i = M - 1;
			arr[i]++;
			do
			{

				if (arr[i] == '0' + 10)
				{
					arr[i] = '0';
					arr[i - 1]++;
				}
				else
					break;
				i--;
			} while (1);
		}
		cout << N << '\n';
		for (i = 0; i < N; i++)
		{
			cout << (arr[i % M]);
		}
}