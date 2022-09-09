#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using D = double;
using uint = unsigned int;

#ifdef WIN32
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

int a[30][30];
int n, m;

void check()
{
	for (int i = 0; i < n; i++)
	{
		int cnt = 0;
		for (int j = 0; j < m; j++) cnt += (a[i][j] != j + 1);
		if (cnt > 2) return;
	}
	cout << "YES\n" << endl;
	exit(0);
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	check();
	for (int i = 0; i < m; i++)
	{
		for (int j = i + 1; j < m; j++)
		{
			for (int t = 0; t < n; t++)
			{
				swap(a[t][i], a[t][j]);
			}
			check();
			for (int t = 0; t < n; t++)
			{
				swap(a[t][i], a[t][j]);
			}
		}
	}
	cout << "NO" << endl;
    return 0;
}