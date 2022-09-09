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

int g[10005];
int poss[5];

int f(int x)
{
    if (x < 100) return g[x];
    if (x % 2 == 1) return 0;
    int t = f(x / 2);
    if (t == 0) return 1;
    if (t == 1) return 2;
    return 1;
}

int main()
{
    for (int i = 1; i <= 10000; i++)
    {
        for (int j = 0; j < 3; j++) poss[j] = 0;
        if (i % 2 == 0) poss[g[i / 2]] = 1;
        poss[g[i - 1]] = 1;
        while (poss[g[i]]) g[i]++;
//         if (f(i) != g[i]) cout << i << ' ' << f(i) << ' ' << g[i] << endl;
    }
    int n, k;
    scanf("%d%d", &n, &k);
    k = k % 2;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        scanf("%d", &a);
        if (k == 0)
        {
            if (a < 3) ans ^= a;
            else ans ^= (1 - a % 2);
        }
        else ans ^= f(a);
    }
    if (ans) cout << "Kevin" << endl;
    else cout << "Nicky" << endl;
    return 0;
}