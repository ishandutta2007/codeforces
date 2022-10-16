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
#define int long long
const int inf = (int)1e9 + 99;

bool isPrime(int x)
{
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0)
            return false;
    return true;
}

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

int32_t main()
{
    _upgrade;

    int n;
    cin >> n;
    vector<int> X(n);
    rep(i, n) cin >> X[i];
    if (n == 1)
    {
        cout << 1 << " " << 1 << endl;
        cout << -X[0] << endl;
        cout << 1 << " " << 1 << endl;
        cout << 0 << endl;
        cout << 1 << " " << 1 << endl;
        cout << 0 << endl;
        exit(0);
    }
    if (n == 2)
    {
        cout << 1 << " " << 1 << endl;
        cout << -X[0] << endl;
        cout << 2 << " " << 2 << endl;
        cout << -X[1] << endl;
        cout << 1 << " " << 1 << endl;
        cout << 0 << endl;
        exit(0);
    }
    int P = -1;
    for (int k = 2; k < n; k++)
        if (2 * k > n && isPrime(k))
        {
            P = k;
            break;
        }
    // debug(P);

    vector<int> R(2 * n);
    for (int i = 0; i < n * 2; i++)
        R[(i * P) % n] = i * P;
    R[n] = R[0];

    cout << 1 << " " << P << endl;
    for (int i = 0; i < P; i++)
    {
        int l = R[n - ((X[i] + n * inf) % n)];
        cout << l << " ";
        X[i] += l;
    }
    cout << endl;

    //  debug(X);

    cout << n - P + 1 << " " << n << endl;
    for (int i = n - P; i < n; i++)
    {
        int l = R[n - ((X[i] + n * inf) % n)];
        cout << l << " ";
        X[i] += l;
    }
    cout << endl;

    // debug(X);

    cout << 1 << " " << n << endl;
    for (int i = 0; i < n; i++)
        cout << -X[i] << " ";
    cout << endl;
}