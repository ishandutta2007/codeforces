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

const int maxn = 205;
const int maxk = 1005;

int ans[maxn][maxn][maxk];
int n, k;
int a[maxn];

inline void upd(int &a, ll b)
{
    a = (a + b) % MOD;
}

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    sort(a, a + n);
    ans[0][0][0] = 1;
    int last = 0;   
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            for (int t = 0; j * (a[i] - last) + t <= k; t++) if (ans[i][j][t] > 0)
            {
//                 cout << i << ' ' << j << ' ' << t << ' ' << ans[i][j][t] << endl;
                if (j > 0)
                {
                    upd(ans[i + 1][j - 1][j * (a[i] - last) + t], (ll)ans[i][j][t] * j);
                    upd(ans[i + 1][j][j * (a[i] - last) + t], (ll)ans[i][j][t] * j);
                }
                upd(ans[i + 1][j + 1][j * (a[i] - last) + t], ans[i][j][t]);
                upd(ans[i + 1][j][j * (a[i] - last) + t], ans[i][j][t]);
            }
        }
        last = a[i];
    }
    int answer = 0;
    for (int t = 0; t <= k; t++) upd(answer, ans[n][0][t]);
    cout << answer << endl;
    return 0;
}