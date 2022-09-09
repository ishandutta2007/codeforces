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

const int MOD = 1000000007;

ll ans[20][20][2];
ll have[20][20];
ll answer, curans;
char m[20];
int n;

void go(int cur, int maxc)
{
    if (cur == 6)
    {
        answer = (answer + curans) % MOD;
        return;
    }
    ll last = curans;
    for (int kv = 0; kv < maxc; kv++)
    {
        curans = (last * have[n][kv]) % MOD;
        have[n][kv]--;
        go(cur + 1, maxc - kv);
        have[n][kv]++;
    }
    return;
}

int main()
{
    scanf("%s", m);
    n = strlen(m);
    memset(ans, 0, sizeof ans);
    ans[0][0][0] = 1;
    for (int i = 0; i <= n; i++)
    {
        for (int s = 0; s <= n; s++)
        {
//             cout << i << ' ' << s << ' ' << ans[i][s][0] << ' ' << ans[i][s][1] << endl;
            for (int j = 0; j < 10; j++)
            {
                int add = (j == 4 || j == 7);
                if (j < m[i] - '0')
                {
                    ans[i + 1][s + add][1] = (ans[i + 1][s + add][1] + ans[i][s][0] + ans[i][s][1]) % MOD;
                } else if (j == m[i] - '0')
                {
                    ans[i + 1][s + add][0] = (ans[i + 1][s + add][0] + ans[i][s][0]) % MOD;
                    ans[i + 1][s + add][1] = (ans[i + 1][s + add][1] + ans[i][s][1]) % MOD;
                } else
                {
                    ans[i + 1][s + add][1] = (ans[i + 1][s + add][1] + ans[i][s][1]) % MOD;
                }
            }
        }
    }
    memset(have, 0, sizeof have);
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            have[i][j] = (ans[i][j][0] + ans[i][j][1]) % MOD;
//             have[i + 1][j] = have[i][j];
        }
    }
    have[n][0]--;
//     for (int i = 0; i <= 2; i++) cout << i << ' ' << (have[n][i]) << endl;
    answer = 0;
    for (int i = 1; i <= n; i++)
    {
        curans = (have[n][i]) % MOD;
        go(0, i);
//         cout << i << ' ' << answer << endl;
    }
    cout << answer << endl;
	return 0;
}