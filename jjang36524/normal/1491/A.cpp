#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int arr[100100];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M;
	cin >> N >> M;
	int i;
	for (i = 0; i < N; i++)
		cin >> arr[i];
	int onc = 0;
	for (i = 0; i < N; i++)
		onc += arr[i];
	for (i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		if (a == 1)
		{
			b--;
			onc -= arr[b];
			arr[b] = 1 - arr[b];
			onc += arr[b];
		}
		else
		{
			cout << (onc >= b)<<'\n';
		}
	}
}