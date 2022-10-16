#include <bits/stdc++.h>
#include <math.h>
#include <chrono>
using namespace std;
#pragma GCC optimize("-Ofast")
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

main()
{
    _upgrade;
    int n, I;
    cin >> n >> I;
    int s = (I * 8) / n;
    s = min(s, 20);
    s = (1 << (s));
    // cerr << s << endl;
    vector<pii> X;
    unordered_map<int, int> M;
    rep(i, n)
    {
        int a;
        cin >> a;
        M[a]++;
    }
    for (pii a : M)
        X.push_back(a);
    sort(all(X));
    // for (auto a : X)
    //     cerr << a.nd << " " << a.st << endl;

    int ile = 0;
    int j = 0;
    int ans = 0;
    rep(i, X.size())
    {
        while (j - i < s && j < X.size())
        {
            ile += X[j].nd;
            j++;
        }
        // what(ile);
        ans = max(ans, ile);
        ile -= X[i].nd;
    }
    cout << n - ans << endl;
}