#include <iostream>
#include <algorithm>
using namespace std;
int arr[100100];
long long N, M;
long long lef, ans;
int main()
{
	cin >> N >> M;
	lef = -M;
	int i;
	for (i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		lef += a;
		arr[i] = b-a;
	}
	sort(arr, arr + N);
	while (lef > 0 &&ans<N)
	{
		lef += arr[ans];
		ans++;
	}
	if (lef > 0)
		cout << -1;
	else
		cout << ans;
}