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

const int inf = 3e18 + 1;

int val(int a, int b, int c)
{
    return (a - b) * (a - b) + (c - b) * (c - b) + (a - c) * (a - c);
}

int solve(vector<int> &A, vector<int> &B, vector<int> &C)
{
    int res = inf;
    for (int a : A)
    {
        auto itrC = lower_bound(all(C), a);
        auto itrB = upper_bound(all(B), a);

        if (itrC != C.end() && itrB != B.begin())
            res = min(res, val(a, *itrC, *(--itrB)));
    }
    return res;
}

vector<int> get(int x)
{
    vector<int> V(x);
    rep(i, x) cin >> V[i];
    sort(all(V));
    return V;
}

int32_t main()
{
    _upgrade;
    int Z;
    cin >> Z;
    while (Z--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        auto A = get(a);
        auto B = get(b);
        auto C = get(c);
        int res = solve(A, B, C);
        res = min(res, solve(A, C, B));
        res = min(res, solve(B, C, A));
        res = min(res, solve(B, A, C));
        res = min(res, solve(C, A, B));
        res = min(res, solve(C, B, A));
        cout << res << endl;
    }
}