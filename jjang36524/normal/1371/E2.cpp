#include <iostream>
#include <algorithm>
#include <string.h>
#define int long long
using namespace std;
int N,M,T;
int arr[100100];
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	int i;
	for (i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + N);
	int s = 0, e = 1LL<<60;
	for (i = 0; i < N; i++)
	{
		s = max(s, arr[i] - i);
		if(i+1>=M)
			e = min(e, arr[i] - i + M-1);
	}
	cout << max(e - s,0LL) << "\n";
	for (i = s; i < e; i++)
	{
		cout << i << ' ';
	}
}