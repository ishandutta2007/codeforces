#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <random>
using namespace std;
int N;
default_random_engine generator;

int gcd(int n, int m)
{
	return m ? gcd(m, n % m) : n;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	uniform_int_distribution<int> distribution(1, N);
	int l = 0, r = 1000000000;
	while (l != r)
	{
		int m = (l + r) / 2;
		cout <<'>'<< ' '<< m << '\n';
		cout.flush();
		int n;
		cin >> n;
		if (n)
		{
			l = m + 1;
		}
		else
		{
			r = m;
		}
	}
	vector<int>t;
	int i;
	for (i = 0; i < 30; i++)
	{
		cout <<"? "<< distribution(generator) << '\n';
		cout.flush();
		int x;
		cin >> x;
		t.push_back(x);
	}
	sort(t.begin(), t.end());
	int ans = 0;
	for (i = 0; i < 30; i++)
	{
		int j;
		for (j = i + 1; j < 30; j++)
		{
			if (j == 1)
			{
				ans = t[j] - t[i];
			}
			else
			{
				ans = gcd(ans, t[j] - t[i]);
			}
		}
	}
	cout<<'!'<< ' '<< l - (N - 1) * ans << ' ' << ans << '\n';
	cout.flush();
}