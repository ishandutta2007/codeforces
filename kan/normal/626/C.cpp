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
    int n, m;
    scanf("%d%d", &n, &m);
    int k6 = 0;
    for (int cur = 1; ; cur++)
    {
        if (cur % 6 == 0) k6++;
        else if (cur % 2 == 0 && n > 0) n--;
        else if (cur % 3 == 0 && m > 0) m--;
        if (k6 >= n + m)
        {
            printf("%d\n", cur);
            return 0;
        }
    }
    return 0;
}