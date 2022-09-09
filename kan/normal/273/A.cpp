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

const int maxn = 100005;

int a[maxn];
int n, m;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    scanf("%d", &m);
    ll curh = 0;
    int curst = 0;
    for (int IT = 0; IT < m; IT++)
    {
        int w, h;
        scanf("%d%d", &w, &h);
        curh = curh + h;
        while (curst < w)
        {
            curh = max(curh, (ll)a[curst] + h);
            curst++;
        }
        printf(LLD "\n", curh - h);
    }
	return 0;
}