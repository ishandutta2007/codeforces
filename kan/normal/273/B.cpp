#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>
#include <cassert>

using namespace std;

typedef long long ll;
typedef long double ld;

#ifdef WIN32
	#define LLD "%I64d"
#else
	#define LLD "%lld"
#endif

int MOD;
const int maxn = 200005;

struct tf
{
    ll mod, st2;
    tf(){}
    tf(ll a, ll b): mod(a), st2(b) {}
    tf(ll a)
    {
        st2 = 0;
        while (a % 2 == 0)
        {
            st2++;
            a /= 2;
        }
        mod = a;
    }
};

inline tf operator *(const tf &a, const tf &b)
{
    return tf((a.mod * b.mod) % MOD, a.st2 + b.st2);
}

tf f[maxn];
pair<int, int> a[maxn];
int n;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i].first);
        a[i].second = i;
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i + n].first);
        a[i + n].second = i;
    }
    scanf("%d", &MOD);
    n *= 2;
    sort(a, a + n);
    int kdiv2 = 0;
    for (int i = 1; i < n; i++) if (a[i] == a[i - 1]) kdiv2++;
//     cout << kdiv2 << endl;
    f[0] = tf(1, 0);
    for (int i = 1; i <= n; i++) f[i] = f[i - 1] * tf(i);
//     cout << f[2].mod << ' ' << f[2].st2 << endl;
    tf ans = tf(1, 0);
    int last = 0;
    a[n] = make_pair(-1, -1);
    for (int i = 1; i <= n; i++)
    {
        if (a[i].first != a[last].first)
        {
            ans = ans * f[i - last];
            last = i;
        }
    }
//     cout << ans.mod << ' ' << ans.st2 << endl;
    ans.st2 -= kdiv2;
    ll answer = ans.mod;
    while (ans.st2 > 0)
    {
        answer = (answer * 2) % MOD;
        ans.st2--;
    }
    cout << answer << endl;
    return 0;
}