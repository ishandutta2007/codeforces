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
    int n, d, h;
    scanf("%d%d%d", &n, &d, &h);
    if (d - h > h)
    {
        printf("-1\n");
        return 0;
    }
    if (d == 1)
    {
        if (n > 2) printf("-1\n");
        else printf("1 2\n");
        return 0;
    }
    for (int i = 2; i <= h + 1; i++) printf("%d %d\n", i - 1, i);
//     cout << "as" << endl;
    for (int i = 0; i < d - h; i++) printf("%d %d\n", i == 0 ? 1 : h + i + 1, h + i + 2);
//     cout << "as" << endl;
    for (int i = d + 2; i <= n; i++) printf("%d %d\n", h, i);
    return 0;
}