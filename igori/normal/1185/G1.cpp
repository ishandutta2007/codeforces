#include <iostream>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include <bitset>
#include <queue>
#include <stack>
#include <deque>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

using std::map;
using std::set;
using std::bitset;
using std::vector;
using std::string;
using std::multimap;
using std::multiset;
using std::deque;
using std::queue;
using std::stack;
using std::pair;
using std::iterator;

using std::sort;
using std::stable_sort;
using std::reverse;
using std::max_element;
using std::min_element;
using std::unique;
using std::ios_base;
using std::swap;
using std::min;
using std::max;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef string S;

namespace MySpace{

};

#define F(i, n) for (int (i) = 0; (i) != (n); (i)++)
#define fi first
#define se second
#define re return
#define all(x) (x).begin(), (x).end()
#define int long long
const ll MOD = 1e9 + 7;
ll n, T;
vector<int> times[3];

long long dp1[2501][51][51];
long long dp2[2501][51][51];
long long dp3[2501][51][51];
long long din[60][60][60];
long long dp[60][60][60][3];
long long Odp[2501][51][51];
long long fact[60];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    dp[1][0][0][0] = 1;
    dp[0][1][0][1] = 1;
    dp[0][0][1][2] = 1;
    fact[0] = 1;
    for (int i = 1; i <= 50; i++)
    {
        fact[i] = fact[i - 1] * i % MOD;
    }
    for (int cn1 = 0; cn1 <= 50; cn1++)
    {
        for (int cn2 = 0; cn2 <= 50; cn2++)
        {
            for (int cn3 = 0; cn3 <= 50; cn3++)
            {
                dp[cn1 + 1][cn2][cn3][0] = (dp[cn1 + 1][cn2][cn3][0] + dp[cn1][cn2][cn3][1] + dp[cn1][cn2][cn3][2]) % MOD;
                dp[cn1][cn2 + 1][cn3][1] = (dp[cn1][cn2 + 1][cn3][1] + dp[cn1][cn2][cn3][0] + dp[cn1][cn2][cn3][2]) % MOD;
                dp[cn1][cn2][cn3 + 1][2] = (dp[cn1][cn2][cn3 + 1][2] + dp[cn1][cn2][cn3][1] + dp[cn1][cn2][cn3][0]) % MOD;
            }
        }
    }
    for (int cnt1 = 0; cnt1 <= 50; cnt1++)
    {
        for (int cnt2 = 0; cnt2 <= 50; cnt2++)
        {
            for (int cnt3 = 0; cnt3 <= 50; cnt3++)
            {
                din[cnt1][cnt2][cnt3] = (dp[cnt1][cnt2][cnt3][0] + dp[cnt1][cnt2][cnt3][1] + dp[cnt1][cnt2][cnt3][2]) % MOD;
                //cout << cnt1 << " " << cnt2 << " " << cnt3 << endl; cout << din[cnt1][cnt2][cnt3] << endl;
            }
        }
    }
    cin >> n >> T;
    for (int i = 0; i < n; i++)
    {
        int t, g;
        cin >> t >> g;
        g--;
        times[g].push_back(t);
    }
    dp1[0][0][0] = 1;
    dp2[0][0][0] = 1;
    dp3[0][0][0] = 1;
    for (int k = 1; k <= times[0].size(); k++)
    {
        for (int tot = 0; tot <= 2500; tot++)
        {
            for (int listen = 0; listen <= times[0].size(); listen++)
            {
                dp1[tot][k][listen] = dp1[tot][k - 1][listen];
                if (tot >= times[0][k - 1] && listen >= 1)
                {
                    dp1[tot][k][listen] += dp1[tot - times[0][k - 1]][k - 1][listen - 1];
                    dp1[tot][k][listen] %= MOD;
                }
            }
        }
    }
    for (int k = 1; k <= times[1].size(); k++)
    {
        for (int tot = 0; tot <= 2500; tot++)
        {
            for (int listen = 0; listen <= times[1].size(); listen++)
            {
                dp2[tot][k][listen] = dp2[tot][k - 1][listen];
                if (tot >= times[1][k - 1] && listen >= 1)
                {
                    dp2[tot][k][listen] += dp2[tot - times[1][k - 1]][k - 1][listen - 1];
                    dp2[tot][k][listen] %= MOD;
                }
            }
        }
    }

    for (int k = 1; k <= times[2].size(); k++)
    {
        for (int tot = 0; tot <= 2500; tot++)
        {
            for (int listen = 0; listen <= times[2].size(); listen++)
            {
                dp3[tot][k][listen] = dp3[tot][k - 1][listen];
                if (tot >= times[2][k - 1] && listen >= 1)
                {
                    dp3[tot][k][listen] += dp3[tot - times[2][k - 1]][k - 1][listen - 1];
                    dp3[tot][k][listen] %= MOD;
                }
            }
        }
    }

    for (int i = 0; i <= T; i++)
    {
        for (int t1 = 0; t1 <= i; t1++)
        {
            int t2 = i - t1;
            for (int c1 = 0; c1 <= times[0].size(); c1++)
            {
                for (int c2 = 0; c2 <= times[1].size(); c2++)
                {
                    Odp[i][c1][c2] += dp1[t1][times[0].size()][c1] * dp2[t2][times[1].size()][c2];
                    if (Odp[i][c1][c2] >= MOD)
                        Odp[i][c1][c2] %= MOD;
                }
            }
        }
    }

    long long ans = 0;
    for (int t12 = 0; t12 <= T; t12++)
    {
        int t3 = T - (t12);
        for (int cn1 = 0; cn1 <= times[0].size(); cn1++)
        for (int cn2 = 0; cn2 <= times[1].size(); cn2++)
        for (int cn3 = 0; cn3 <= times[2].size(); cn3++)
        {
            long long add = Odp[t12][cn1][cn2] * dp3[t3][times[2].size()][cn3] % MOD *
                            din[cn1][cn2][cn3] % MOD * fact[cn1] % MOD * fact[cn2] % MOD * fact[cn3] % MOD;
            ans = (ans + add);
        }
    }
    cout << ans % MOD;
}