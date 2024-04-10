#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <set>
#include <queue>
#include <unordered_set>
#include <complex>
#include <unordered_map>
#include <bitset>
#include <ctime>
#include <cassert>
#include <random>

#define sz(a) (int)((a).size())

using namespace std;

mt19937 rnd(239);

typedef long long ll;
typedef long double ld;

struct T
{
    ll ch, zn;
    int ind;
    ll ch2, zn2;
    T():
        ch(0),
        zn(0),
        ind(0),
        ch2(0),
        zn2(0) {}
     T(ll ch, ll zn, int ind, ll ch2, ll zn2):
        ch(ch),
        zn(zn),
        ind(ind),
        ch2(ch2),
        zn2(zn2) {}

};

bool kek(ll a, ll b, ll c, ll d)
{
    if (b < 0)
        a *= -1, b *= -1;
    if (d < 0)
        c *= -1, d *= -1;
    return a * d < b * c;
}

bool ok = false;

bool cmp(T a, T b)
{
    if (a.ch * b.zn != a.zn * b.ch)
        return kek(a.ch, a.zn, b.ch, b.zn);
    if (a.ch2 * b.zn2 != a.zn2 * b.ch2)
        return kek(b.ch2, b.zn2, a.ch2, a.zn2);
    return ((a.ind < b.ind) ^ ok);
}

ll func(vector<int> &a)
{
    if (a.size() == 1) return 0;
    vector<int> v1, v2;
    for (int i = 0; i < (a.size() / 2); i++)
        v1.push_back(a[i]);
    for (int i = (a.size() / 2); i < a.size(); i++)
        v2.push_back(a[i]);
    ll ans = func(v1) + func(v2);
    int c1 = 0;
    int c2 = 0;
    a.clear();
    while (c1 != v1.size() || c2 != v2.size())
    {
        if (c1 == v1.size())
        {
            a.push_back(v2[c2]);
            c2++;
            continue;
        }
        if (c2 == v2.size())
        {
            a.push_back(v1[c1]);
            ans += v2.size();
            c1++;
            continue;
        }
        if (v1[c1] < v2[c2])
        {
            a.push_back(v1[c1]);
            ans += c2;
            c1++;
            continue;
        }
        else
        {
            a.push_back(v2[c2]);
            c2++;
            continue;
        }
    }
    return ans;
}

ll num(vector<int> a, vector<int> b)
{
    int n = a.size();
    vector<int> id(n, 0);
    for (int i = 0; i < n; i++)
        id[a[i]] = i;
    for (int i = 0; i < n; i++)
        b[i] = id[b[i]];
    return (func(b));
}

int solve()
{
    ios::sync_with_stdio(0);
    int n;
    if (!(cin >> n))
    {
        return 1;
    }
    ll w;
    cin >> w;
    vector<ll> x(n), v(n);
    for (int i = 0; i < n; i++)
        cin >> x[i] >> v[i];
    vector<T> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        a[i] = T(v[i] - w, x[i], i, v[i] + w, x[i]);
        b[i] = T(v[i] + w, x[i], i, v[i] - w, x[i]);
    }
    ok = false;
    sort(a.begin(), a.end(), cmp);
    ok = true;
    sort(b.begin(), b.end(), cmp);
    vector<int> c, d;
    for (int i = 0; i < n; i++)
    {
        c.push_back(a[i].ind);
        d.push_back(b[i].ind);
    }
    cout << num(c, d) << endl;
    return 0;
}

int32_t main()
{
    #ifdef ONPC
        freopen("in.txt", "r", stdin);
    #endif
    int T = 100;
    //cin >> T;
    for (int i = 1; i <= T; i++)
    {
        #ifdef ONPC
            cerr << "Test #" << i << ":\n";
        #endif
        if (solve())
            break;
        #ifdef ONPC
            cerr << "_______________________________________________" << endl;
        #endif
    }
    #ifdef ONPC
        cerr << endl << "finished in " << clock() * 1000LL / CLOCKS_PER_SEC << " ms" << endl;
    #endif
    return 0;
}