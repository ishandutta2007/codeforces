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

const ld eps = 1e-7;

int n, l;
vector<ld> solve(vector<int> A)
{
    vector<ld> T(sz(A));
    T[0] = 0;
    for (int i = 1; i < n + 2; i++)
        T[i] = T[i - 1] + (ld)(abs(A[i] - A[i - 1])) / i;
    return T;
}

int32_t main()
{
    _upgrade;
    int Z;
    cin >> Z;
    while (Z--)
    {

        cin >> n >> l;
        vector<int> A(n + 2);
        A[0] = 0;
        A[n + 1] = l;
        rep(i, n) cin >> A[i + 1];
        vector<ld> T1 = solve(A);

        reverse(all(A));
        vector<ld> T2 = solve(A);
        reverse(all(T2));
        reverse(all(A));

        // debug(T1);
        //debug(T2);

        for (int i = 0; i < n + 2; i++)
            if (T1[i] - eps < T2[i] && T2[i + 1] - eps < T1[i + 1])
            {

                ld t = max(T1[i], T2[i + 1]);
                ld dist = A[i + 1] - A[i];
                // debug(i, t, dist, T1[i], T2[i + 1]);
                dist -= (i + 1) * (t - T1[i]);
                dist -= (n + 1 - i) * (t - T2[i + 1]);
                t += dist / (n + 2);
                cout << t << endl;
                break;
            }
    }
}