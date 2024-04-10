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

vector<int> prime_factors(int x)
{
    vector<int> res;
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            while (x % i == 0)
                x /= i;
            res.push_back(i);
        }
    }

    if (x != 1)
        res.push_back(x);
    return res;
}

int big(int p, int q, int d)
{
    while (p % q == 0)
        p /= d;
    return p;
}

int32_t main()
{
    _upgrade;
    int Z;
    cin >> Z;
    while (Z--)
    {
        int p, q;
        cin >> p >> q;
        auto prime = prime_factors(q);
        debug(prime);

        int res = 0;
        for (auto a : prime)
            res = max(res, big(p, q, a));

        cout << res << endl;
    }
}