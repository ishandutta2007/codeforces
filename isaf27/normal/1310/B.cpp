//#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

//defines
typedef long long ll;
typedef long double ld;
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define prev _prev
#define y0 _y0
#define kill _kill

//permanent constants
const ld pi = acos(-1.0);
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int digarr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int alf = 26;
const int dig = 10;
const int two = 2;
const int th = 3;
const ll prost = 239;
const ll btc = 30;
const ld eps = 1e-8;
const ll INF = (ll)(1e18 + 239);
const int BIG = (int)(1e9 + 239);
const int MOD = 1e9 + 7; //

//random
mt19937 rnd(239); //(chrono::high_resolution_clock::now().time_since_epoch().count());

//constants
const int M = (int)((1 << 17) + 239);
const int N = (int)(2e3 + 239);
const int L = 20;
const int T = (1 << 18) + 239;
const int B = 500;
const int X = 5010;

int n, k, a[M];

vector<int> solve(int l, int r)
{
    if (r - l == 2)
    {
        vector<int> res(4, -BIG);
        res[a[l] * 2 + a[l + 1]] = (int)(a[l] | a[l + 1]);
        res[a[l + 1] * 2 + a[l]] = (int)(a[l] | a[l + 1]);
        return res;
    }
    int mid = (l + r) >> 1;
    vector<int> s1 = solve(l, mid);
    vector<int> s2 = solve(mid, r);
    vector<int> res(4, -BIG);
    for (int m1 = 0; m1 < 4; m1++)
        for (int m2 = 0; m2 < 4; m2++)
            if (s1[m1] != -BIG && s2[m2] != -BIG)
            {
                vector<int> t(4);
                t[0] = (m1 >> 1);
                t[1] = (m2 >> 1);
                t[2] = (m1 & 1);
                t[3] = (m2 & 1);
                int cur = s1[m1] + s2[m2];
                cur += (int)(t[0] | t[1]);
                cur += (int)(t[2] | t[3]);
                for (int w1 = 0; w1 < 2; w1++)
                    for (int w2 = 2; w2 < 4; w2++)
                    {
                        int l1 = 1 - w1;
                        cur += (int)(t[w2] | t[l1]);
                        for (int w : {l1, w2})
                            res[t[w] + 2 * t[w1]] = max(res[t[w] + 2 * t[w1]], cur);
                        cur -= (int)(t[w2] | t[l1]);
                    }
            }
    return res;
}

int32_t main()
{
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i < k; i++)
    {
        int x;
        cin >> x;
        x--;
        a[x] = 1;
    }
    if (k == 0)
    {
        cout << 0 << "\n";
        return 0;
    }
    vector<int> ans = solve(0, (1 << n));
    int res = max(ans[0], ans[1] + 1);
    res = max(res, ans[2] + 1);
    res = max(res, ans[3] + 1);
    cout << res << "\n";
    return 0;
}