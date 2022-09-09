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

const int maxn = 1e5 + 5;
const int maxx = 1e5 + 5;
const int MOD = 1000000007;

int a[maxn];
vector<int> d;
int n;

ll powmod(ll a, int b)
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

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    sort(a, a + n);
    ll answer = 0;
    for (int i = 2; i <= maxx; i++)
    {
//         cout << i << endl;
        d.resize(0);
        for (int j = 1; j <= min((int)sqrt(i) + 5, i); j++) if (i % j == 0)
        {
            int ij = i / j;
            if (ij < j) break;
            d.push_back(j);
            if (ij > j) d.push_back(ij);
        }
        sort(d.begin(), d.end());
        d.push_back(maxx + 5);
//         for (int j = 0; j < d.size(); j++) cout << d[j] << ' ';
//         cout << endl;
        ll curans = 1;
        int last = 0;
        for (int j = 0; j < (int)d.size() - 1; j++)
        {
            int cur = lower_bound(a, a + n, d[j + 1]) - a;
//             cout << cur << endl;
            curans = (curans * powmod(j + 1, cur - last)) % MOD;
//             cout << "now " << d[j + 1] << ' ' << curans << ' ' << last << ' ' << cur << endl;
            last = cur;
        }
//         cout << "now all " << curans << endl;
        answer = (answer + curans) % MOD;
        d.resize(d.size() - 2);
        d.push_back(maxx + 5);
        last = 0;
        curans = 1;
        for (int j = 0; j < (int)d.size() - 1; j++)
        {
            int cur = lower_bound(a, a + n, d[j + 1]) - a;
            curans = (curans * powmod(j + 1, cur - last)) % MOD;
//             cout << "now " << d[j + 1] << ' ' << curans << ' ' << last << ' ' << cur << endl;
            last = cur;
        }
//         cout << "now all " << curans << endl;
        answer = (answer - curans + MOD) % MOD;
//         cout << "answer " << answer << endl;
    }
    cout << (answer + 1) % MOD << endl;
	return 0;
}