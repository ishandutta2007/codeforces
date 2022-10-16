#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <unordered_map>
#include <set>
#include <map>
#pragma warning(disable:4996)
using namespace std;
unordered_map<signed, signed>pl[200100];
unordered_map<int, int>pl2[200100];
int mi[200100];
long long ans = 1;
void ch(int n, int s, int e)
{
	pl[n][s]--;
	pl[n][e]++;
	while (!pl[n].count(mi[n]) || pl[n][mi[n]] == 0)
	{
		mi[n]++;
		ans *= n;
		ans %= 1000000007;
	}
}
signed main()
{
	int N, Q;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> Q;
	int i;
	for (i = 2; i <= 200000; i++)
		pl[i][0] = N;
	for (i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		int na = a;
		int j;
		for (j = 2; j * j <= a; j++)
		{
			int cor = 0;
			while (na % j == 0)
			{
				cor++;
				na /= j;
			}
			if (cor == 0)
				continue;
			ch(j, 0, cor);
			pl2[i][j] += cor;
		}
		if (na != 1)
		{
			ch(na, 0, 1);
			pl2[i][na]++;
		}
	}
	while (Q--)
	{
		int a, b;
		cin >> a >> b;
		a--;
		int na = b;
		int j;
		for (j = 2; j * j <= b; j++)
		{
			int cor = 0;
			while (na % j == 0)
			{
				cor++;
				na /= j;
			}
			if (cor == 0)
				continue;
			ch(j, pl2[a][j], pl2[a][j] + cor);
			pl2[a][j] += cor;
		}
		if (na != 1)
		{
			ch(na, pl2[a][na], pl2[a][na] + 1);
			pl2[a][na]++;
		}
		cout << ans << '\n';
	}
}