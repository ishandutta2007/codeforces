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

const int MAXN = (int)1e5 + 99;
const int MAXR = 2 * 1005;
pii tab[MAXN];
int T[MAXN];
int res[MAXN];

inline int dist(pii A, pii B)
{
    return abs(A.st - B.st) + abs(A.nd - B.nd);
}

int32_t
main()
{
    _upgrade;
    int r, n;
    cin >> r >> n;
    T[0] = 0;
    tab[0] = {1, 1};

    for (int i = 1; i <= n; i++)
    {
        cin >> T[i] >> tab[i].st >> tab[i].nd;
    }
    int maks = 0;

    for (int i = 1; i <= n; i++)
    {
        res[i] = -MAXN;
        for (int j = max(0, i - MAXR); j < i; j++)
            if (dist(tab[i], tab[j]) <= T[i] - T[j])
                res[i] = max(res[i], res[j] + 1);
        // debug(i, res[i]);
        maks = max(maks, res[i]);
    }

    cout << maks << endl;
}