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
#define ld long double

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

pii ab(pii A, pii B)
{
    return {A.st - B.st, A.nd - B.nd};
}
pii maks(pii A, pii B)
{
    return {max(A.st, B.st), max(A.nd, B.nd)};
}
int dod(int a)
{
    return max(a, 0);
}

int32_t main()
{
    _upgrade;
    int n, m;
    cin >> n >> m;

    vector<pii> A(n);
    vector<pii> B(m);
    rep(i, n) cin >> A[i].st >> A[i].nd;
    rep(i, m) cin >> B[i].st >> B[i].nd;

    vector<pii> X;
    rep(i, n) rep(j, m) X.push_back(ab(B[j], A[i]));
    sort(all(X));
    reverse(all(X));

    X.push_back({-1, -1});
    // debug(X);

    pii res = {X[0].st, -11};
    int wynik = 1e9;
    for (auto x : X)
    {
        res.st = x.st;
        wynik = min(wynik, dod(res.st + 1) + dod(res.nd + 1));
        res.nd = max(res.nd, x.nd);
    }

    cout << wynik << endl;
}