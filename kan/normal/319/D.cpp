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

const int maxn = 50005;

char s[2][maxn];
int len;

int main()
{
// 	int bt = clock();
	scanf("%s", s[0]);
	int n = strlen(s[0]);
	int wh = 0;
	for (int len = 1; len * 2 <= n; len++)
	{
		int cnt = 0;
		int nextn = 0;
		for (int i = 0; i + len < n; i++)
		{
			s[wh ^ 1][nextn++] = s[wh][i];
			cnt = (s[wh][i] == s[wh][i + len] ? cnt + 1 : 0);
			if (cnt == len)
			{
				nextn -= len;
				cnt = 0;
			}
		}
		for (int i = n - len; i < n; i++) s[wh ^ 1][nextn++] = s[wh][i];
		n = nextn;
		wh ^= 1;
// 		s[wh][n] = '\0';
// 		printf("%s\n", s[wh]);
	}
// 	printf("%lf\n", (double)(clock() - bt) / CLOCKS_PER_SEC);
	s[wh][n] = '\0';
	printf("%s\n", s[wh]);
	return 0;
}