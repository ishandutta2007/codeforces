#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>
#include <cassert>
#include <ctime>

using namespace std;

typedef long long ll;
typedef long double ld;

#ifdef WIN32
	#define LLD "%I64d"
#else
	#define LLD "%lld"
#endif

const int maxn = 2005;

int t[maxn], h[maxn], m[maxn];
bool used[maxn];
int n, x;

int main()
{
	scanf("%d%d", &n, &x);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d%d", &t[i], &h[i], &m[i]);
	}
	int answer = 0;
	for (int IT = 0; IT < 2; IT++)
	{
		for (int i = 0; i < n; i++) used[i] = false;
		int curt = IT;
		int curx = x;
		int curans = 0;
		while (true)
		{
			int cur = -1;
			int curm = -1;
			for (int i = 0; i < n; i++) if (!used[i] && t[i] == curt && h[i] <= curx && m[i] > curm)
			{
				curm = m[i];
				cur = i;
			}
			if (cur == -1) break;
			curans++;
			used[cur] = true;
			curx += m[cur];
			curt ^= 1;
		}
		answer = max(answer, curans);
	}
	cout << answer << endl;
	return 0;
}