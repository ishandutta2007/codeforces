#include <bits/stdc++.h>
#include <math.h>
#include <chrono>
using namespace std;
#pragma GCC optimize("-O3")
#define endl "\n"
#define mp make_pair
#define st first
#define nd second
#define pii pair<int, int>
#define pb push_back
#define _upgrade ios_base::sync_with_stdio(0), cout.setf(ios::fixed), cout.precision(10), cin.tie(0), cout.tie(0);
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define FWD(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define fwd(i, a, b) for (int i = (a); i < (b); ++i)
#define all(c) (c).begin(), (c).end()
#define sz(X) (int)((X).size())
#define what(x) cerr << #x << " is " << x << endl;

ostream &operator<<(ostream &out, string str)
{
    for (char c : str)
        out << c;
    return out;
}
template <class L, class R>
ostream &operator<<(ostream &out, pair<L, R> p)
{
    return out << "(" << p.st << ", " << p.nd << ")";
}
template <class T>
auto operator<<(ostream &out, T a) -> decltype(a.begin(), out)
{
    out << '{';
    for (auto it = a.begin(); it != a.end(); it = next(it))
        out << (it != a.begin() ? ", " : "") << *it;
    return out << '}';
}
void dump() { cerr << "\n"; }
template <class T, class... Ts>
void dump(T a, Ts... x)
{
    cerr << a << ", ";
    dump(x...);
}
#define debug(...) cerr << "[" #__VA_ARGS__ "]: ", dump(__VA_ARGS__)

#define int long long
const int inf = 1e9;

void finito()
{
    cout << -1 << endl;
    exit(0);
}

int32_t main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    vector<int> wys(n, -1);
    vector<pii> res;

    rep(i, n) cin >> A[i];

    vector<vector<int>> X(4);

    rep(i, n) X[A[i]].push_back(i);

    // debug(X);

    int cnt = n;

    rep(i, sz(X[3]))
    {
        int a = X[3][i];
        if (i == 0)
        {
            wys[a] = cnt;
            res.push_back(mp(a, cnt));
        }
        if (i + 1 != sz(X[3]))
        {
            int b = X[3][i + 1];
            wys[b] = wys[a] - 1;
            res.push_back(mp(b, wys[a]));
            res.push_back(mp(b, wys[b]));
        }
        cnt--;
    }

    //   debug(res);

    if (sz(X[3]) > 0)
    {
        int a = X[3].back();
        int b;
        if (sz(X[2]) > 0 && X[2].back() > a)
            b = X[2].back();

        else
        {
            auto q = upper_bound(all(X[1]), a);
            if (q == X[1].end())
                finito();
            b = *q;
            X[1].erase(q);
        }
        wys[b] = wys[a] - 1;
        res.push_back(mp(b, wys[a]));
        res.push_back(mp(b, wys[b]));
        cnt--;
    }

    // debug(res);

    if (sz(X[2]) > sz(X[1]))
        finito();

    reverse(all(X[2]));

    for (auto a : X[2])
    {
        if (wys[a] == -1)
        {
            wys[a] = cnt--;
            res.push_back(mp(a, wys[a]));
        }

        int b = X[1].back();
        X[1].pop_back();

        if (b < a)
            finito();

        wys[b] = wys[a];
        res.push_back(mp(b, wys[b]));
    }

    //   debug(res);

    for (auto a : X[1])
    {
        wys[a] = cnt--;
        res.push_back(mp(a, wys[a]));
    }

    // sort(all(res));
    // debug(res);
    cout << res.size() << endl;
    for (auto p : res)
        cout << (n - p.nd + 1) << " " << p.st + 1 << endl;
}