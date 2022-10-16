#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
#define int long long
int d[1010];
int uf[1010];
int siz[1010];
int siz2[1010];
int f(int n)
{
	return uf[n] == n ? n : uf[n] = f(uf[n]);
}
void u(int n, int m)
{
	n = f(n);
	m = f(m);
	if (n == m)
		return;
	siz[m] += siz[n];
	siz2[m] += siz2[n];
	uf[f(n)] = uf[f(m)];
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		int N;
		cin >> N;
		int i;
		for (i = 0; i < N; i++)
		{
			cin >> d[i];
			uf[i] = i;
			siz[i] = 1;
			siz2[i] = d[i];
		}
		int c = 0;
		while (1)
		{
			pair<int, int>ma = { 0LL,0LL };
			for (i = 0; i < N; i++)
			{
				if (siz2[f(i)] > siz[f(i)]* siz[f(i)])
				{
					ma = max(ma, { d[i],i });
				}
			}
			if (ma.first == 0)
				break;
			int v = ma.second;
			for (i = 0; i < ma.first; i++)
			{
				if (siz2[f(v)] <= siz[f(v)] * siz[f(v)])
				{
					break;
				}
				c++;
				assert(c != N);
				cout << "? " << v+1 << '\n';
				cout.flush();
				int a;
				cin >> a;
				u(v, a - 1);
			}
		}
		cout << "! ";
		for (i = 0; i < N; i++)
		{
			cout << f(i) + 1<< ' ';
		}
		cout << '\n';
		cout.flush();
		
	}
}