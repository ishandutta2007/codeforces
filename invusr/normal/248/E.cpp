#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

typedef double r32;
typedef unsigned u32;

inline int getint()
{
	static char c;
	while ((c = getchar()) < '0' || c > '9');

	int res = c - '0';
	while ((c = getchar()) >= '0' && c <= '9')
		res = res * 10 + c - '0';
	return res;
}

const int MaxN = 100005;
const int MaxM = 100005;
const int MaxP = 105;
const int MaxK = 5;

int n, m;
int pot[MaxN], cur[MaxN];
r32 pro[MaxN][MaxP];
r32 outcome = 0.0;

inline void remove(int fr, int to)
{
	int k = cur[fr];
	for (int i = 0; i <= pot[fr]; ++i)
		pro[fr][i] = pro[fr][i] * (k - i) / k + pro[fr][i + 1] * (i + 1) / k;
	--cur[fr];
}

int main()
{
	n = getint();
	for (int i = 1; i <= n; ++i)
	{
		pot[i] = cur[i] = getint();
		pro[i][pot[i]] = 1.0;
		outcome += pot[i] == 0;
	}

	m = getint();
	while (m--)
	{
		int u = getint(), v = getint();
		int k = getint();

		outcome -= pro[u][0];
		for (int i = 0; i < k; ++i)
			remove(u, v);
		outcome += pro[u][0];
		cur[v] += k;

		printf("%.16f\n", outcome);
	}

	return 0;
}