#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>

using namespace std;

typedef long long ll;
typedef long double ld;

#ifdef WIN32
	#define LLD "%I64d"
#else
	#define LLD "%lld"
#endif

const int maxn = 105;

int kvl[maxn], kvr[maxn];
bool like[maxn];
char name[maxn];
int n, m, k;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d%d", &m, &k);
    like[0] = true;
    for (int i = 0; i < k; i++)
    {
        int a;
        scanf("%d", &a);
        like[a] = true;
    }
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int d;
        scanf("%s", name);
        scanf("%d", &d);
        kvl[i] = 0;
        kvr[i] = 0;
        for (int j = 0; j < d; j++)
        {
            int a;
            scanf("%d", &a);
            if (like[a]) kvr[i]++;
            if (like[a] && a > 0) kvl[i]++;
        }
        kvr[i] = min(kvr[i], k);
        kvl[i] = max(kvl[i], d - (m - k));
    }
    for (int i = 0; i < n; i++)
    {
        bool can0 = true;
        bool can1 = true;
        for (int j = 0; j < n; j++) if (j != i)
        {
            if (kvr[j] > kvl[i]) can0 = false;
            if (kvr[i] < kvl[j]) can1 = false;
        }
        if (can0) printf("0\n");
        else if (can1) printf("2\n");
        else printf("1\n");
    }
	return 0;
}