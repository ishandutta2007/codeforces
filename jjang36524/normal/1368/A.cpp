#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;
int N, M, a, b, c, d;
int arr[1000100];
signed main()
{
	ios_base::sync_with_stdio(false);
	cin >> d;
	while (d--)
	{
		cin >> N >> M >> a;
		if (N > M)
			swap(N, M);
		int s = 0;
		while (max(N, M) <= a)
		{
			if (s % 2)
			{
				M += N;
			}
			else
			{
				N += M;
			}
			s++;
		}
		cout << s << '\n';
	}
}