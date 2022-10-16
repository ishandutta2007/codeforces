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
#define what(x) cerr << #x << " is " << x << endl;
#define int long long

main()
{
    _upgrade;
    int Z;
    cin >> Z;
    while (Z--)
    {
        int n, m;
        cin >> n >> m;
        // vector<long long> val(n);
        vector<pair<vector<int>, long long>> G(n);

        rep(i, n) cin >> G[i].nd;
        rep(i, m)
        {
            int a, b;
            cin >> a >> b;
            // G[--a].st.push_back(--b);
            G[--b].st.push_back(--a);
        }

        vector<pair<vector<int>, long long>> Gp;
        long long sum = 0;
        for (auto Q : G)
        {
            sort(all(Q.st));
            if (Q.st.size())
            {
                sum += Q.nd;
                Gp.push_back(Q);
            }
        }
        G = Gp;

        sort(all(G));

        vector<long long> X;
        vector<int> cur;
        long long val = sum;

        for (auto &Q : G)
            if (Q.st == cur)
            {
                val += Q.nd;
            }
            else
            {
                X.push_back(val);
                cur = Q.st;
                val = Q.nd;
            }
        X.push_back(val);

        for (auto x : X)
        {
            // what(x);
            sum = gcd(sum, x);
        }
        cout << sum << endl;
    }
}