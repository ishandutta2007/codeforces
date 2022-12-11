#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back

#define sz(a) (int) (a).size()
#define all(a) (a).begin(), (a).end()

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector <int> vi;

int n;
vector <ll> tsum;
vector <pll> tprogr;

void add(int v, int tl, int tr, int l, int r, ll d) /**on [l, r] +d to everyone**/
{
    if (l > r) return;
    if (tl == l && tr == r) {tsum[v] += d; return;}
    int tm = (tl + tr) / 2;
    if (r <= tm) add(v * 2, tl, tm, l, r, d);
    else if (l > tm) add(v * 2 + 1, tm + 1, tr, l, r, d);
    else
    {
        add(v * 2, tl, tm, l, tm, d);
        add(v * 2 + 1, tm + 1, tr, tm + 1, r, d);
    }
}

ll getsum(int v, int tl, int tr, int pos)
{
    if (tl == tr) return tsum[v];
    int tm = (tl + tr) / 2;
    if (pos <= tm) return getsum(v * 2, tl, tm, pos) + tsum[v];
    else return getsum(v * 2 + 1, tm + 1, tr, pos) + tsum[v];
}

void arifm(int v, int tl, int tr, int l, int r, ll a0, ll d) /**add arithmetical progression (a0, d) for [l, r]**/
{
    if (l > r) return;
    if (tl == l && tr == r) {tprogr[v].first += a0; tprogr[v].second += d; return;}
    int tm = (tl + tr) / 2;
    if (r <= tm) arifm(v * 2, tl, tm, l, r, a0, d);
    else if (l > tm) arifm(v * 2 + 1, tm + 1, tr, l, r, a0, d);
    else
    {
        arifm(v * 2, tl, tm, l, tm, a0, d);
        arifm(v * 2 + 1, tm + 1, tr, tm + 1, r, a0 + (tm - l + 1) * d, d);
    }
}

ll getprogr(int v, int tl, int tr, int pos)
{
    if (tl == tr) return tprogr[v].first;
    int tm = (tl + tr) / 2;
    if (pos <= tm) return getprogr(v * 2, tl, tm, pos) + tprogr[v].first + (pos - tl) * tprogr[v].second;
    else return getprogr(v * 2 + 1, tm + 1, tr, pos) + tprogr[v].first + (pos - tl) * tprogr[v].second;
}

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    string s;
    cin >> s;

    n = sz(s);
    tsum.resize(4 * n);
    tprogr.resize(4 * n);

    for (int i = 0; i < n; i++)
        if (s[i] == 'A' || s[i] == 'E' || s[i] == 'Y' || s[i] == 'U' || s[i] == 'I' || s[i] == 'O')
    {
        ll l = (ll) min((ll) n - (ll) i, (ll) i + 1) - 1;
        ll r = (ll) max((ll) n - (ll) i, (ll) i + 1);
        arifm(1, 0, n - 1, 0, l, 1, 1);
        add(1, 0, n - 1, l + 1, r - 1, l + 1);
        arifm(1, 0, n - 1, r, n - 1, n - r, -1);
    }

    ld ans = 0;

    for (int i = 0; i < n; i++)
        ans += (getsum(1, 0, n - 1, i) + getprogr(1, 0, n - 1, i)) * 1.0 / (i + 1);

    cout << fixed;
    cout.precision(10);
    cout << ans << "\n";

}