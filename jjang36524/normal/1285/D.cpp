#include <iostream>
#include <algorithm>
using namespace std;
int N;
int arr[100100];
int ms(int nownum, int p, int l, int r)
{
	if (p == 0)
		return 0;
	int m = lower_bound(arr, arr + N, nownum + p)-arr;
	if (m == l)
		return ms(nownum + p, p / 2, l, r);
	if (m == r + 1)
		return ms(nownum, p / 2, l, r);
	return min(ms(nownum + p, p / 2, m, r), ms(nownum, p / 2, l, m - 1))+p;
}
int main()
{
	cin >> N;
	int i;
	for (i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + N);
	cout << ms(0, 1 << 29, 0, N - 1);
}