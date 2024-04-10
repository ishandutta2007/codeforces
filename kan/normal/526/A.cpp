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

#define pb push_back
#define all(x) begin(x), end(x)

const int maxn = 1005;

char s[maxn];
int n;

int main()
{
	scanf("%d", &n);
	scanf("%s", s);
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			bool ok = true;
			for (int k = 0; k < 5; k++) if (s[i + (j - i) * k] != '*') ok = false;
			if (ok)
			{
				printf("yes\n");
				return 0;
			}
		}
	}
	printf("no\n");
	return 0;
}