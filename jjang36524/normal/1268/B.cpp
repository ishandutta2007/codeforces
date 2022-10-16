#include <iostream>
#include <algorithm>
using namespace std;
#define int long long
int N,M;
int arr[300100];

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	int bigger = 0;
	int i;
	int w = 0;
	int b = 0;
	for (i = 0; i < N; i++)
		cin >> arr[i];
	for (i = 0; i < N; i++)
	{
		if (i % 2)
		{
			b += (arr[i] + 1) / 2;
			w += arr[i] / 2;
		}
		else
		{
			w += (arr[i] + 1) / 2;
			b += arr[i] / 2;
		}
	}
	cout << min(w, b);
}