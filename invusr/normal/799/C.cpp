#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

inline int getint()
{
	static char c;
	while ((c = getchar()) < '0' || c > '9');

	int res = c - '0';
	while ((c = getchar()) >= '0' && c <= '9')
		res = res * 10 + c - '0';
	return res;
}

inline int get()
{
	static char c;
	while ((c = getchar()) != 'C' && c != 'D');
	return c - 'C';
}

template <class T>
inline void relax(T &a, const T &b)
{
	if (b > a)
		a = b;
}

const int MaxN = 100005;
const int N = 100000;
const int INF = N * 233;

int n, total[2];
int bit[2][N + 1], best[2];

inline void bit_add(int *bit, int x, int w)
{
	for (int i = x; i <= N; i += i & -i)
		relax(bit[i], w);
}
inline int bit_query(int *bit, int x)
{
	int res = -INF;
	for (int i = x; i > 0; i ^= i & -i)
		relax(res, bit[i]);
	return res;
}

int main()
{
	cin >> n >> total[0] >> total[1];

	best[0] = best[1] = -INF;
	for (int i = 1; i <= N; ++i)
		bit[0][i] = bit[1][i] = -INF;

	int res = 0;
	for (int i = 1; i <= n; ++i)
	{
		int v = getint(), w = getint(), t = get();

		if (w <= total[t])
		{
			relax(res, v + best[!t]);
			relax(res, v + bit_query(bit[t], total[t] - w));
			relax(best[t], v);
		}

		bit_add(bit[t], w, v);
	}

	cout << res << endl;

	return 0;
}