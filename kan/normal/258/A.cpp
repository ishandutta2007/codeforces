#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>
#include <cassert>

using namespace std;

typedef long long ll;
typedef long double ld;

#ifdef WIN32
	#define LLD "%I64d"
#else
	#define LLD "%lld"
#endif

const int maxn = 1e5 + 5;

char s[maxn];

int main()
{
    scanf("%s", s);
    int n = strlen(s);
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0' || i == n - 1)
        {
            for (int j = i + 1; j < n; j++) printf("%c", s[j]);
            return 0;
        }
        printf("%c", s[i]);
    }
	return 0;
}