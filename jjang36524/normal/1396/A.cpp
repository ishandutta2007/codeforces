#include <iostream>
#include <algorithm>
#define int long long
using namespace std;
void extgcd(int a, int b, int* x, int* y)
{
	if (b == 0)
	{
		*x = 1;
		*y = 0;
		return;
	}
	int x1, x2;
	extgcd(b, a % b, &x1, &x2);
	*x = x2;
	int q = a / b;
	*y = x1 - q * x2;
}
int N;
pair<int, int>t[100100];
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	int i;
	for (i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		if (!i)
		{
			t[0] = { 0LL,-a };
		}
		else
		{
			int x, y;
			extgcd(N,N-1,&x, &y);
			x *= a;
			y *= a;
			t[i] = { -x,-y };
		}
	}
	cout << 1 << ' ' << N << '\n';
	for (i = 0; i < N; i++)
	{
		cout << t[i].first*N << ' ';
	}
	cout << '\n';
	cout << 1 << ' ' << 1 << '\n';
	cout << t[0].second << '\n';
	if (i == 1)
	{
		cout << 1 << ' ' << 1 << '\n';
		cout << t[1].second << '\n';
	}
	else
	{
		cout << 2 << ' ' << N << '\n';
		for (i = 1; i < N; i++)
		{
			cout << t[i].second * (N - 1) << ' ';
		}
	}
	
}