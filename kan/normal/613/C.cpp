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

const int maxlen = 100005;
const int maxn = 30;

int a[maxn];
char ans[maxlen];
int n;

int main()
{
    scanf("%d", &n);
    int cnt1 = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        if (a[i] % 2 == 1) cnt1++;
    }
    if (cnt1 > 1)
    {
        printf("0\n");
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < a[i]; j++) printf("%c", 'a' + i);
        }
        printf("\n");
        return 0;
    }
    int g = 0;
    for (int i = 0; i < n; i++) g = __gcd(a[i], g);
    for (int i = 0; i < n; i++) a[i] /= g;
    cnt1 = 0;
    for (int i = 0; i < n; i++) if (a[i] % 2) cnt1++;
    int answer = g;
    if (cnt1 > 1)
    {
        for (int i = 0; i < n; i++) a[i] *= 2;
        g /= 2;
    }
    int len = accumulate(a, a + n, 0);
    int cur = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < a[i] / 2; j++)
        {
            ans[cur] = 'a' + i;
            ans[len - cur - 1] = 'a' + i;
            cur++;
        }
        if (a[i] % 2 == 1) ans[len / 2] = 'a' + i;
    }
    ans[len] = '\0';
    printf("%d\n", answer);
    for (int i = 0; i < g; i++) printf("%s", ans);
    printf("\n");
    return 0;
}