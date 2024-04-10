#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>
#include <cassert>
#include <ctime>

using namespace std;

typedef long long ll;
typedef long double ld;

#ifdef WIN32
	#define LLD "%I64d"
#else
	#define LLD "%lld"
#endif

#define pb push_back
#define all(x) begin(x), end(x)

const int MOD = 1000000007;
const int maxn = 2005;
const int maxsz = 200005;

int powmod(int a, int b)
{
    ll ans = 1;
    ll tmp = a;
    while (b)
    {
        if (b & 1) ans = (ans * tmp) % MOD;
        tmp = (tmp * tmp) % MOD;
        b >>= 1;
    }
    return ans;
}

struct pt
{
    int x, y;
};

inline bool operator<(const pt &a, const pt &b)
{
    if (a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}

pt p[maxn];
int h, w, n;
int fact[maxsz], invfact[maxsz];
int ans[maxn];

inline int c(int n, int k)
{
    ll down = ((ll)invfact[k] * invfact[n - k]) % MOD;
    return (fact[n] * down) % MOD;
}

inline int cnt(int x1, int y1, int x2, int y2)
{
    int dx = x2 - x1;
    int dy = y2 - y1;
    return c(dx + dy, dx);
}

int main()
{
    scanf("%d%d%d", &h, &w, &n);
    int MAX = h + w;
    fact[0] = 1;
    invfact[0] = 1;
    for (int i = 1; i < MAX; i++)
    {
        fact[i] = ((ll)fact[i - 1] * i) % MOD;
        invfact[i] = powmod(fact[i], MOD - 2);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &p[i].x, &p[i].y);
        p[i].x--;
        p[i].y--;
    }
    p[n].x = 0;
    p[n].y = 0;
    n++;
    sort(p, p + n);
    for (int i = n - 1; i >= 0; i--)
    {
        ans[i] = cnt(p[i].x, p[i].y, h - 1, w - 1);
        for (int j = i + 1; j < n; j++) if (p[j].x >= p[i].x && p[j].y >= p[i].y)
        {
            ans[i] = ((ans[i] - (ll)ans[j] * cnt(p[i].x, p[i].y, p[j].x, p[j].y)) % MOD + MOD) % MOD;
        }
    }
    cout << ans[0] << endl;
	return 0;
}