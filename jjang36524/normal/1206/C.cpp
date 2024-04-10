#include <iostream>
using namespace std;
int N;
int output[200100];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	if (!(N % 2))
	{
		cout << "NO";
		return 0;
	}
	int i;
	for (i = 1; i <= N; i++)
	{
		if (i % 2)
		{
			output[i - 1] = 2 * i - 1;
			output[N + i - 1] = 2 * i;
		}
		else
		{
			output[i - 1] = 2 * i;
			output[N + i - 1] = 2 * i-1;
		}
	}
	cout << "YES" << '\n';
	for (i = 0; i < 2 * N; i++)
	{
		cout << output[i] << ' ';
	}
}