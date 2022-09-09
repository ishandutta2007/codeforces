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

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    scanf("%d", &n);
    int k = 0;
    int kv = 1;
    while (kv < n)
    {
        k++;
        kv *= 2;
    }
    printf("%d\n", k);
    for (int i = 0; i < k; i++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++) if (j & (1 << i)) cnt++;
        printf("%d", cnt);
        for (int j = 0; j < n; j++) if (j & (1 << i)) printf(" %d", j);
        printf("\n");
    }
    return 0;
}