#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using D = double;
using uint = unsigned int;

#ifdef WIN32
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

#define pb push_back
#define mp make_pair
#define all(x) begin(x), end(x)
#define fi first
#define se second

int main()
{
    int n, a, b;
    scanf("%d%d%d", &n, &a, &b);
    if (a * b < n)
    {
        printf("-1\n");
        return 0;
    }
    int k0 = (n + 1) / 2;
    int k1 = n / 2;
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            if ((i + j) % 2 == 0)
            {
                if (k0 > 0)
                {
                    printf("%d ", k0 * 2 - 1);
                    k0--;
                } else printf("0 ");
            }
            if ((i + j) % 2 == 1)
            {
                if (k1 > 0)
                {
                    printf("%d ", k1 * 2);
                    k1--;
                } else printf("0 ");
            }
        }
        printf("\n");
    }
    return 0;
}