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

int32_t main()
{
    _upgrade;
    int n;
    cin >> n;
    if (n <= 2)
    {
        cout << 0 << endl;
        exit(0);
    }
    int pot = 0;
    while ((1 << (pot + 1)) < n)
        pot++;
    what(pot);

    vector<pii> Q;
    rep(i, pot)
        rep(S, 1 << pot) if (S & (1 << i)) Q.emplace_back(S, S ^ (1 << i));

    vector<pii> R;
    for (auto q : Q)
        R.emplace_back(n - q.st, n - q.nd);

    for (auto &q : Q)
        q.st++, q.nd++;

    Q.insert(Q.end(), all(R));

    cout << sz(Q) << endl;

    for (auto q : Q)
        cout << q.st << " " << q.nd << endl;
}