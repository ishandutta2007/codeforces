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

int val(int x, int m)
{
    if (m >= x)
        return m;
    int a = x / m;
    int r = x % m;

    return a * a * (m - r) + (a + 1) * (a + 1) * r;
}

int32_t main()
{
    int n, k;
    cin >> n >> k;

    vector<int> M(n);
    vector<int> X(n, 1);

    rep(i, n) cin >> M[i];
    sort(all(M));
    //   debug(M);

    int res = 0;
    for (int a : M)
        res += a * a;

    k -= n;
    priority_queue<pii> Q;
    rep(i, n) Q.push(make_pair(val(M[i], 1) - val(M[i], 2), i));

    while (k > 0)
    {
        k--;
        auto q = Q.top();
        Q.pop();

        int i = q.nd;
        X[i]++;
        Q.push(make_pair(val(M[i], X[i]) - val(M[i], X[i] + 1), i));

        res -= q.st;

        // debug(q);
        // debug(res);
    }
    // debug(M);
    // debug(X);
    cout << res << endl;
}