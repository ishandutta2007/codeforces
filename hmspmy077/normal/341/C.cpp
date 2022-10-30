#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

#define pb push_back
#define mp make_pair
#define sz(a) ((int)(a).size())

const int N = 2005;
const int mo = 1000000007;

long long f[N][N], g[N];
int a[N];
bool visit[N];

int main()
{
    #ifdef LOCAL_TEST
        freopen("a.in","r",stdin);
    //  freopen("a.out","w",stdout);
    #endif
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    int p = 0;
    int q = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] == -1)
        {
            ++p;
            continue;
        }
        if (visit[i]) continue;
        vector<int> b;
        int j = i;
        while (1)
        {
            if (j == -1 || visit[j]) break;
            visit[j] = true;
            b.pb(j);
            j = a[j];
        }
        if (a[b.back()] == a[0]) continue;
        bool flag = false;
        for (int j = 1; j <= n; ++j)
            if (a[j] == i)
            {
                flag = true;
                break;
            }
        if (flag)
        {
            for (int j = 0; j < sz(b); ++j)
                visit[b[j]] = false;
        }
        else
            ++q;
    }
    p -= q;
    g[1] = 0;
    g[2] = 1;
    for (int i = 3; i <= n; ++i)
        g[i] = (g[i - 1] + g[i - 2]) * (i - 1) % mo;
    f[p][q] = 1;
    for (int i = n; i >= 0; --i)
        for (int j = n; j >= 0; --j)
        {
            if (i == 0 && j > 0)
                (f[i][j - 1] += f[i][j] * j) %= mo;
            if (i)
                (f[i - 1][j] += f[i][j] * j) %= mo;
            if (i > 1)
                (f[i - 2][j + 1] += f[i][j] * (i - 1)) %= mo;
        }
    long long ans = f[0][0];
//  for (int i = 1; i <= n; ++i)
//      (ans += f[i][0] * g[i]) %= mo;
    cout << ans << endl;
    return 0;
}