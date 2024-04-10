#include <iostream>
#include <algorithm>
#include <vector>
#define int long long
using namespace std;
int N;
int hp[1 << 21];
int ct[1 << 21];
int x, g;
int getm(int n)
{
	if (hp[n * 2] == hp[n * 2 + 1])
	{
		return n >= (1 << g);
	}
	else
	{
		return (hp[n * 2] > hp[n * 2 + 1]) ? getm(n * 2) : getm(n * 2 + 1);
	}
}
void de(int n)
{
	ct[n]--;
	if (hp[n * 2] == hp[n * 2 + 1])
	{
		hp[n] = 0;
	}
	else
	{
		if (hp[n * 2] > hp[n * 2 + 1])
		{
			hp[n] = hp[n * 2];
			de(n * 2);
		}
		else
		{
			hp[n] = hp[n * 2 + 1];
			de(n * 2 + 1);
		}
	}
}
vector<int>o;
void df(int n)
{
	if (n >= (1 << g))
		return;
	while (1)
	{

		if (getm(n))
		{
			de(n);
			o.push_back(n);
		}
		else
		{
			df(n * 2);
			df(n * 2 + 1);
			return;
		}
	}
	
}

signed main()
{
	int T;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	int i;
	while (T--)
	{

		cin >> x >> g;
		int i;
		for (i = 1; i < (1 << x); i++)
		{
			cin >> hp[i];
		}
		for (i = (1 << x) - 1; i > 0; i--)
		{
			ct[i] = ct[i * 2] * 2 + (i >= (1 << g));
		}
		df(1);
		int s = 0;
		for (i = 1; i < (1 << g); i++)
		{
			s += hp[i];
		}
		cout << s << '\n';
		for (i = 0; i < o.size(); i++)
			cout << o[i] << ' ';
		cout << '\n';
		for (i = 1; i < (1 << x); i++)
		{
			hp[i] = ct[i] = 0;
		}
		o.clear();
	}
}