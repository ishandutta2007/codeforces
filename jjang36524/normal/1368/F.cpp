#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
#define int long long
int bl[1001];
int ch[1001];
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	int sq = sqrt(N);
	if (sq == 1)
	{
		cout << 0<<endl;
		return 0;
	}
	int i, j;
	pair<int, int>ma = { 0,0 };
	for (i = 1; i <= N; i++)
	{
		ma = max(ma, { N - i - (N+i-1)/i+1,i });
	}
	int k = ma.second;
	for (i = 0; i < N; i += k)
	{
		bl[i] = 1;
	}
	while (1)
	{
		int r = 0;
		for (i = 0; i < N; i++)
		{
			r += 1 - (ch[i]||bl[i]);
		}
		if (r < k)
		{
			cout << 0 << endl;
			return 0;
		}
		cout << k << ' ';
		r = 0;
		for (i = 0; i < N; i++)
		{
			if (r == k)
				continue;
			if (!(ch[i] || bl[i]))
			{
				ch[i] = 1;
				r++;
				cout << i + 1 << ' ';
			}
		}
		cout << endl;
		int a;
		cin >> a;
		for (i = a; i <k+a; i++)
		{
			ch[(i - 1) % N] = 0;
		}
	}
}