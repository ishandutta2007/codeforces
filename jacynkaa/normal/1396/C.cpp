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
const int MAXN = (int)1e6 + 99;

int gun, laser, awp, d;
int dp[MAXN][2];
int A[MAXN];

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

int minn(int a, int b, int c)
{
    return min(min(a, b), c);
}
int bez(int a)
{
    return a * min(gun, awp) + awp;
}
int z(int a)
{
    return min(laser + minn(gun, awp, laser), a * min(gun, awp) + min(2 * gun, awp));
}

int32_t
main()
{
    _upgrade;
    int n;
    cin >> n >> gun >> laser >> awp >> d;
    rep(i, n) cin >> A[i];
    dp[n][0] = dp[n][1] = -d;
    for (int i = n - 1; i >= 0; i--)
    {
        dp[i][1] = dp[i + 1][0] + z(A[i]) + d;
        dp[i][0] = min(bez(A[i]) + dp[i + 1][0] + d, z(A[i]) + dp[i + 1][1] + 3 * d);
        if (i == n - 2)
            dp[i][0] = min(dp[i][0], z(A[i]) + dp[i + 1][0] + 2 * d);

        // debug(i, dp[i][0], dp[i][1]);
    }
    cout << dp[0][0] << endl;
}