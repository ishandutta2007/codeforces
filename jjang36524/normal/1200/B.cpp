#include <iostream>
#include <algorithm>
using namespace std;
int N, M, K;
int T;
int arr[101];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cin >> T;
	while (T--)
	{
		cin >> N >> M >> K;
		int i;
		for (i = 0; i < N; i++)
		{
			cin >> arr[i];
		}
		for (i = 0; i < N - 1; i++)
		{
			if (arr[i] >= arr[i + 1] - K)
			{
				M += arr[i] - max(arr[i + 1] - K,0);
			}
			else
			{
				M -= arr[i + 1] - arr[i] - K;
				if (M < 0)
				{
					cout << "NO"<< '\n';
					goto F;
				}
			}
			
		}
		cout << "YES"<<'\n';
	F:
		int d;
	}
}