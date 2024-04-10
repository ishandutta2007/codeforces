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
#include <complex>
#include <iomanip>
#include <stdio.h>
#include <string.h>

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
using std::fill;

using std::setprecision;
using std::fixed;

using std::min;
using std::max;

#define int long long

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

inline int nextInt()
{
    int x = 0;
    char c = getchar();
    int mi = (c == '-');
    if (c == '-') c = getchar();
    while ('0' <= c && c <= '9')
    {
        x = 10 * x + c - '0';
        c = getchar();
    }
    if (mi) return x * -1;
    return x;
}

void solve()
{
    int n;
    vector<ll> p;
    ll x, a;
    ll y, b;
    ll k;
    cin >> n;
    p.resize(n);
    F(i, n) cin >> p[i];
    vector<ll> pref(n + 1);
    cin >> x >> a;
    cin >> y >> b;
    if (y < x)
    {
        swap(x, y);
        swap(a, b);
    }
    cin >> k;
    sort(all(p));
    reverse(all(p));
    int t = 0;
    ll cntA = 0, cntB = 0, cntBOTH = 0;
    for (int i = 1; i <= n; i++) pref[i] = pref[i - 1] + p[i - 1];
    for (int i = 0; i < n; i++)
    {
        if ((i + 1) % a == 0 && (i + 1) % b == 0)
        {
            cntBOTH++;
        }
        else
        {
            if ((i + 1) % a == 0) cntA++;
            if ((i + 1) % b == 0) cntB++;
        }
        //cout << cntBOTH << " " << cntA << " " << cntB << endl;
        ll r = 0;
        r += (pref[cntBOTH] - pref[0]) / 100 * (x + y);
        r += (pref[cntBOTH + cntA] - pref[cntBOTH]) / 100 * (x);
        r += (pref[cntBOTH + cntA + cntB] - pref[cntBOTH + cntA]) / 100 * (y);
        if (r >= k)
        {
            cout << i + 1 << "\n";
            t = 1;
            break;
        }
        ll s = 0;
        s += (pref[cntBOTH] - pref[0]) / 100 * (x + y);
        s += (pref[cntBOTH + cntB] - pref[cntBOTH]) / 100 * (y);
        s += (pref[cntBOTH + cntB + cntA] - pref[cntBOTH + cntB]) / 100 * (x);
        if (s >= k)
        {
            cout << i + 1 << "\n";
            t = 1;
            break;
        }
        //cout << r << " " << s << endl;
    }
    if (t == 0)
    {
        cout << -1 << "\n";
    }
}

signed main()
{
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    while (q--)
    {
        solve();
    }
}