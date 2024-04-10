#include <iostream>
#include <algorithm>
#define int long long
using namespace std;
long long N, K;
long long arr[100100];
long long leftopr[100100];
long long rightopr[100100];
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> K;
	int i;
	for (i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + N);
	for (i = 1; i < N; i++)
	{
		leftopr[i] = i * (arr[i] - arr[i - 1]);
	}
	for (i = N - 2; i >= 0; i--)
	{
		rightopr[i] = (N - 1 - i) * (arr[i + 1] - arr[i]);
	}
	long long leftbor = 0;
	long long rightbor = N - 1;
	long long ans;
	while ((K >= leftopr[leftbor + 1]+rightopr[rightbor - 1]))
	{
			leftbor++;
			if (leftbor < rightbor)
				rightbor--;
			K -= leftopr[leftbor] + rightopr[rightbor];
		if (leftbor == rightbor)
			break;
	}
	ans = arr[rightbor] - arr[leftbor];
	if (arr[leftbor] < arr[rightbor])
		ans -= K / min((N - rightbor), leftbor + 1);
	cout << ans;
}