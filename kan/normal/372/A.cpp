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

const int maxn = 500005;

int n;
int a[maxn];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    sort(a, a + n);
    int cur = 0;
    while (cur < n - cur) cur++;
    int curkv = 0;
    for (int i = 0; i + 1 <= n - (i + 1); i++)
    {
        while (cur < n && a[cur] < a[i] * 2)
        {
            cur++;
            curkv = max(0, curkv - 1);
        }
        curkv++;
        if (curkv > (n - cur))
        {
            printf("%d\n", n - i);
            return 0;
        }
    }
    printf("%d\n", n - n / 2);
	return 0;
}