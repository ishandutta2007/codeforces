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
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    for (int i = 0; i * a <= c; i++)
    {
        if ((c - i * a) % b == 0)  { printf("Yes\n"); return 0; }
    }
    printf("No\n");
    return 0;
}