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

const int MOD = 998244353;
const int MAXN = 400000;

int silnia[MAXN + 2];

int mult(int a, int b)
{
    a = (a + MOD * MOD) % MOD;
    b = (b + MOD * MOD) % MOD;
    return (a * b) % MOD;
}

int szybkie(int a, int b)
{
    if (b == 0)
        return 1;
    int x = szybkie(a, b / 2);
    int P = mult(x, x);
    if (b % 2 == 1)
        P = mult(P, a);
    return P;
}

int odw(int a)
{
    return szybkie(a, MOD - 2);
}

int dwumian(int a, int b)
{
    int res = mult(mult(silnia[a], odw(silnia[b])), odw(silnia[a - b]));
    debug(a, b, res);
    return res;
}

void pre()
{
    silnia[0] = 1;
    rep(i, MAXN) silnia[i + 1] = mult(silnia[i], i + 1);
}

int32_t main()
{
    _upgrade;
    pre();
    int n;
    cin >> n;
    vector<int> X(2 * n);
    rep(i, 2 * n) cin >> X[i];
    sort(all(X));

    int res = 0;
    int T = dwumian(2 * n - 1, n - 1);
    rep(i, 2 * n)
    {
        if (i < n)
        {
            // int a = 2 * n - 1 - i;
            // int b = i;
            res += 2 * mult(-X[i], T);
            res %= MOD;
        }
        else
        {
            // int a = i;
            // int b = 2 * n - i - 1;
            res += 2 * mult(X[i], T);
            res %= MOD;
        }
        // debug(res);
    }
    cout << (res % MOD) << endl;
}