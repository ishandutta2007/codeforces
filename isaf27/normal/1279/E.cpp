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
const ld eps = 1e-10;
const ll INF = (ll)(1e18 + 239);
const int BIG = (int)(1e9 + 239);
const int MOD = 998244353; //(int)(1e9 + 7); //998244353;
const ll MOD2 = (ll)MOD * (ll)MOD;

//random
mt19937 rnd(239); //(chrono::high_resolution_clock::now().time_since_epoch().count());

//constants
const int M = (int)(1e6 + 239);
const int N = (int)(2e3 + 239);
const int L = 20;
const int T = (1 << 20);
const int B = 500;
const int X = 55;

ll sum(ll a, ll b)
{
    if (a + b >= INF)
        return INF;
    return a + b;
}

ll prod(ll a, ll b)
{
    if (a == 0 || b == 0)
        return 0;
    if (a >= INF || b >= INF)
        return INF;
    if (a <= (INF / b))
        return a * b;
    return INF;
}

ll fact[X], dp[X];

vector<int> get_perm(int n, ll k)
{
    if (n == 0)
        return {};
    vector<int> p = get_perm(n - 1, k % fact[n - 1]);
    vector<int> ans = {(int)(k / fact[n - 1])};
    vector<int> val;
    for (int i = 0; i < n; i++)
        if (i != ans[0])
            val.push_back(i);
    for (int i : p)
        ans.push_back(val[i]);
    return ans;
}

bool cmpsec(pair<int, int> a, pair<int, int> b)
{
    return (a.second < b.second);
}

vector<int> gett(int n, ll k)
{
    if (n == 0)
        return {};
    if (n == 1)
        return {0};
    vector<int> ans(n);
    vector<pair<int, int>> al;
    for (int i = 0; i < n - 1; i++)
        al.push_back(make_pair(i, i));
    for (int i = 1; i < n - 1; i++)
    {
        pair<int, int> cur;
        for (int t = 0; t < (int)al.size(); t++)
            if (al[t].first == i)
            {
                swap(al[t], al.back());
                cur = al.back();
                al.pop_back();
                break;
            }
        sort(al.begin(), al.end(), cmpsec);
        ll ost = fact[(int)al.size() - 1];
        int id = k / ost;
        k %= ost;
        ans[i] = al[id].second;
        al[id].second = cur.second;
    }
    ans[n - 1] = al[0].second;
    ans[0] = n - 1;
    return ans;
}

int n;
ll k;

void solve()
{
    cin >> n >> k;
    k--;
    if (k >= dp[n])
    {
        cout << "-1\n";
        return;
    }
    int was = 0;
    while (n > 0)
    {
        for (int i = 0; i < n; i++)
        {
            ll cur = prod(fact[max(0, i - 1)], dp[n - i - 1]);
            if (cur > k)
            {
                vector<int> nxt = gett(i + 1, k / dp[n - i - 1]);
                for (int t : nxt)
                    cout << t + was + 1 << " ";
                k %= dp[n - i - 1];
                n -= i + 1;
                was += i + 1;
                break;
            }
            k -= cur;
        }
    }
    cout << "\n";
}

int32_t main()
{
#ifdef ONPC
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    fact[0] = 1;
    for (int i = 1; i < X; i++)
        fact[i] = prod(fact[i - 1], i);
    dp[0] = 1;
    for (int i = 1; i < X; i++)
    {
        dp[i] = 0;
        for (int j = 0; j < i; j++)
            dp[i] = sum(dp[i], prod(fact[max(0, j - 1)], dp[i - j - 1]));
    }
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}