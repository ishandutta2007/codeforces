#include <bits/stdc++.h>
using namespace std;

const int LIM = 65536;

long long ans, MOD = 1ll<<32;
vector<int> no[LIM];
int n, a, b, c, d;

void proc(int i)
{
	long long f = 0;
	f += a; f *= i; f %= MOD;
	f += b; f *= i; f %= MOD;
	f += c; f *= i; f %= MOD;
	f += d; f %= MOD;
	for (long long j = i;j <= n;j*=i)
	{
		ans += f*(n/j);
		ans %= MOD;
	}
}

int main()
{
	cin >> n >> a >> b >> c >> d;
	proc(2);
	for (int i = 3;i <= n;i+=2)
	{
		if (no[i%LIM].empty())
		{
			if (i < 20000) no[(3*i)%LIM].push_back(i);
			proc(i);
		} else
		{
			for (int u: no[i%LIM]) no[(2*u+i)%LIM].push_back(u);
			no[i%LIM].clear();
		}
	}
	cout << ans << endl;
	return 0;
}