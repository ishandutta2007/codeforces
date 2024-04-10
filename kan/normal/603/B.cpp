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

const int MOD = 1000000007;

bool was[1000006];

int main()
{
    int k, p;
    cin >> p >> k;
    if (k == 0)
    {
        int ans = 1;
        for (int i = 0; i < p - 1; i++) ans = ((ll)ans * p) % MOD;
        cout << ans << endl;
    } else if (k == 1)
    {
        int ans = 1;
        for (int i = 0; i < p; i++) ans = ((ll)ans * p) % MOD;
        cout << ans << endl;
    } else
    {
        int cur = 1;
        int len = 0;
        while (!was[cur])
        {
            len++;
            was[cur] = true;
            cur = ((ll)cur * k) % p;
        }
        int kv = (p - 1) / len;
        int ans = 1;
        for (int i = 0; i < kv; i++) ans = ((ll)ans * p) % MOD;
        cout << ans << endl;
    }
    return 0;
}