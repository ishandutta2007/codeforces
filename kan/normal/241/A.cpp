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

const int maxn = 1005;

int d[maxn], s[maxn], maxs[maxn];
int n, k;

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%d", &d[i]);
    for (int i = 0; i < n; i++) scanf("%d", &s[i]);
    maxs[0] = s[0];
    for (int i = 1; i < n; i++) maxs[i] = max(s[i], maxs[i - 1]);
    int cur = 0;
    int kv = s[0];
    int ans = 0;
    while (cur < n)
    {
        while (cur < n && kv >= d[cur]) 
        {
            kv -= d[cur];
            ans += d[cur];
            cur++;
            kv += s[cur];
        }
        if (cur == n) break;
//         cout << cur << ' ' << kv << ' ' << ans << endl;
        ans += k;
        kv += maxs[cur];
    }
    cout << ans << endl;
	return 0;
}