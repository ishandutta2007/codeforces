#include <iostream>
#include <algorithm>
using namespace std;
int N,M,D;
int arr[1010];
int startpos[1010];
int f[1010];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N>>M>>D;
	int i;
	int sum = 0;
	for (i = 0; i < M; i++)
	{
		cin >> arr[i];
		sum += arr[i];
	}
	int nowpos = 0;
	for (i = 0; i < M; i++)
	{
		int startps = 0;
		startps = min(nowpos+D, N + 1 - sum);
		startpos[i] = startps;
		nowpos = startps + arr[i] - 1;
		sum -= arr[i];
	}
	if (nowpos + D <= N)
	{
		cout << "NO" << '\n';
		return 0;
	}
	for (i = 0; i < M; i++)
	{
		int j;
		for (j = 0; j < arr[i]; j++)
		{
			f[j + startpos[i]] = i + 1;
		}
	}
	cout << "YES" << '\n';
	for (i = 1; i <= N; i++)
	{
		cout << f[i] << ' ';
	}
}