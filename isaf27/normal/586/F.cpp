/*
    Author: isaf27 (Ivan Safonov)
*/

//#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

//defines
typedef long long ll;
typedef double ld;
#define TIME clock() * 1.0 / CLOCKS_PER_SEC

//permanent constants
const ld pi = acos(-1.0);
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int digarr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int alf = 26;
const int dig = 10;
const int two = 2;
const int th = 3;
const ll prost = 239;
const ll bt = 31;
const ld eps = 1e-8;
const ll INF = 1e18 + 239;
const int BIG = 2e9 + 239;
const int MOD = 1e9 + 7;
const ll MOD2 = (ll)MOD * (ll)MOD;

//random
mt19937_64 rnd(239); //(chrono::high_resolution_clock::now().time_since_epoch().count());

//constants
const int M = 2e5 + 239;
const int N = 2e3 + 239;
const int L = 30;
const int T = (1 << 20);
const int B = trunc(sqrt(M)) + 1;
const int X = 1e4 + 239;

struct Hasher {
    const size_t P = 239239239;
  size_t operator() ( pair<ll, ll> x ) const { return (x.first * P + x.second); }
};

unordered_map<pair<ll, ll>, pair<ll, ll>, Hasher> m1, m2;
int n, k1, k2;
ll a[L], b[L], c[L], v1[L][th], v2[L][th];
string people;

ll number(ll x, ll r)
{
    return 1LL << (3 * x + r);
}

void go1(int b, ll s1, ll s2, ll s, ll mask)
{
    if (k1 == b && b != 0)
    {
        if (m1.find(make_pair(s1, s2)) == m1.end())
            m1[make_pair(s1, s2)] = make_pair(s, mask);
        else
            m1[make_pair(s1, s2)] = max(m1[make_pair(s1, s2)], make_pair(s, mask));
        return;
    }
    ll now = mask;
    mask |= number(b, 0);
    mask |= number(b, 1);
    go1(b + 1, s1 + v1[b][0] - v1[b][1], s2 + v1[b][1], s + v1[b][0] + v1[b][1], mask);
    mask = now;
    mask |= number(b, 0);
    mask |= number(b, 2);
    go1(b + 1, s1 + v1[b][0], s2 - v1[b][2], s + v1[b][0] + v1[b][2], mask);
    mask = now;
    mask |= number(b, 1);
    mask |= number(b, 2);
    go1(b + 1, s1 - v1[b][1], s2 + v1[b][1] - v1[b][2], s + v1[b][2] + v1[b][1], mask);
}

void go2(int b, ll s1, ll s2, ll s, ll mask)
{
    if (k2 == b && b != 0)
    {
        if (m2.find(make_pair(s1, s2)) == m2.end())
            m2[make_pair(s1, s2)] = make_pair(s, mask);
        else
            m2[make_pair(s1, s2)] = max(m2[make_pair(s1, s2)], make_pair(s, mask));
        return;
    }
    ll now = mask;
    mask |= number(b, 0);
    mask |= number(b, 1);
    go2(b + 1, s1 + v2[b][0] - v2[b][1], s2 + v2[b][1], s + v2[b][0] + v2[b][1], mask);
    mask = now;
    mask |= number(b, 0);
    mask |= number(b, 2);
    go2(b + 1, s1 + v2[b][0], s2 - v2[b][2], s + v2[b][0] + v2[b][2], mask);
    mask = now;
    mask |= number(b, 1);
    mask |= number(b, 2);
    go2(b + 1, s1 - v2[b][1], s2 + v2[b][1] - v2[b][2], s + v2[b][2] + v2[b][1], mask);
}

int32_t main()
{
    #ifdef ONPC
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    people = "LMW";
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i] >> c[i];
    if (n == 1)
    {
        if (b[0] == 0 && c[0] == 0)
        {
            cout << "MW";
            return 0;
        }
        if (a[0] == 0 && c[0] == 0)
        {
            cout << "LW";
            return 0;
        }
        if (a[0] == 0 && b[0] == 0)
        {
            cout << "LM";
            return 0;
        }
        cout << "Impossible";
        return 0;
    }
    k1 = n / 2;
    for (int i = 0; i < k1; i++)
        v1[i][0] = a[i], v1[i][1] = b[i], v1[i][2] = c[i];
    for (int i = k1; i < n; i++)
        v2[i - k1][0] = a[i], v2[i - k1][1] = b[i], v2[i - k1][2] = c[i];
    k2 = n - k1;
    go1(0, 0, 0, 0, 0);
    go2(0, 0, 0, 0, 0);
    ll ans = -INF;
    ll mask1 = 0;
    ll mask2 = 0;
    for (auto x = m1.begin(); x != m1.end(); x++)
    {
        pair<pair<ll, ll>, pair<ll, ll> > t = *x;
        pair<ll, ll> fnd = make_pair(-t.first.first, -t.first.second);
        if (m2.find(fnd) == m2.end())
            continue;
        ll now = t.second.first + m2[fnd].first;
        if (now > ans)
        {
            ans = now;
            mask1 = m1[t.first].second;
            mask2 = m2[fnd].second;
        }
    }
    if (ans == -INF)
    {
        cout << "Impossible";
        return 0;
    }
    for (int i = 0; i < k1; i++)
    {
        for (int h = 0; h < 3; h++)
            if (mask1 & number(i, h))
                cout << people[h];
        cout << "\n";
    }
    for (int i = 0; i < k2; i++)
    {
        for (int h = 0; h < 3; h++)
            if (mask2 & number(i, h))
                cout << people[h];
        cout << "\n";
    }
    return 0;
}