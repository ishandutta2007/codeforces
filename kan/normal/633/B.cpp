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
    int n;
    scanf("%d", &n);
    int now = 0;
    for (int i = 5; ; i += 5)
    {
        int cur = i;
        while (cur % 5 == 0)
        {
            cur /= 5;
            now++;
        }
        if (now == n)
        {
            printf("%d\n", 5);
            for (int j = 0; j < 5; j++) printf("%d ", i + j);
            printf("\n");
            return 0;
        }
        if (now > n) break;
    }
    printf("%d\n", 0);
    return 0;
}