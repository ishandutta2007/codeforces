#include <iostream>
#include <algorithm>
using namespace std;
int N;
int x, y;
int arr[200100];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	int i;
	int ans = 0;
	for (i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + N);
	int j = 0;
	while (j < N)
	{
		while (j<N&&arr[j] <= ans)
		{
			j++;
		}
		if (j != N)
		{
			j++;
			ans++;
		}
			
	}
	cout << ans;
}