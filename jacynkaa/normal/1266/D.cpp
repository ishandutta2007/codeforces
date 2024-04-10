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
#define _upgrade ios_base::sync_with_stdio(0), cout.setf(ios::fixed), cout.precision(10) //cin.tie(0); cout.tie(0);
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define FWD(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define fwd(i, a, b) for (int i = (a); i < (b); ++i)
#define all(c) (c).begin(), (c).end()
#define what(x) cerr << #x << " is " << x << endl;
#define int long long

const int MAXN = 1e6;
int val[MAXN];

vector<pair<pii, int>> E;
vector<pii> X;
int n, m;

void pre()
{
    cin >> n >> m;
    rep(i, m)
    {
        int a, b, c;
        cin >> a >> b >> c;
        val[--a] += c;
        val[--b] -= c;
    }
    rep(i, n)
        X.push_back({val[i], i});
    sort(all(X));
    cerr << "wtf" << endl;
    rep(i, n) cerr << X[i].st << " " << X[i].nd << endl;
}

void solve()
{
    for (int i = 0; i < X.size(); i++)
    {
        while (X[i].st != 0)
        {
            if (abs(X.back().st) > abs(X[i].st))
            {
                E.push_back({{X[i].nd, X.back().nd}, abs(X[i].st)});
                X.back().st += X[i].st;
                X[i].st = 0;
            }
            else
            {
                E.push_back({{X[i].nd, X.back().nd}, X.back().st});
                X[i].st += X.back().st;
                X.pop_back();
            }
        }
    }
    cout << E.size() << endl;
    for (auto P : E)
        cout << P.st.nd + 1 << " " << P.st.st + 1 << " " << P.nd << endl;
}
main()
{
    _upgrade;
    pre();
    solve();
}