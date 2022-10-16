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

int32_t main()
{
    _upgrade;
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> A(n);

        bool dwaw = (n == 1);
        bool jest = false;

        rep(i, n) cin >> A[i];

        A.push_back(-1);
        A.push_back(-1);
        rep(i, n)
        {
            if (A[i] == k)
                jest = true;
            if (A[i] >= k && (A[i + 1] >= k || A[i + 2] >= k))
                dwaw = true;
        }
        cout << ((jest && dwaw) ? "yes" : "no") << endl;
    }
}