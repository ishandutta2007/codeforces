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

char t[1010];
int n, k;

int main()
{
	scanf("%d%d", &n, &k);
	char * s = t + 2;
	scanf("%s", s);
	for (int i = n - 1; i >= 0; i--)
	{
		while (++s[i] < 'a' + k)
		{
			if (s[i] == s[i - 1] || s[i] == s[i - 2]) continue;
			for (int j = i + 1; j < n; j++)
			{
				s[j] = 'a';
				while (s[j] == s[j - 1] || s[j] == s[j - 2]) s[j]++;
			}
			printf("%s", s);
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}