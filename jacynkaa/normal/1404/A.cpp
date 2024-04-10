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

int k, n;

bool ok(string S)
{

    vector<char> X(k, '?');
    rep(i, n)
    {
        if (S[i] == '0')
        {
            if (X[i % k] == '1')
                return false;
            X[i % k] = '0';
        }
        if (S[i] == '1')
        {
            if (X[i % k] == '0')
                return false;
            X[i % k] = '1';
        }
    }

    int s1 = 0;
    int s2 = 0;
    for (char c : X)
    {
        if (c == '1')
            s1++;
        if (c == '0')
            s2++;
    }

    return s2 <= k / 2 && s1 <= k / 2;
}

int32_t main()
{
    _upgrade;
    int Z;
    cin >> Z;
    while (Z--)
    {

        cin >> n >> k;
        string S;
        cin >> S;
        cout << (ok(S) ? "YES" : "NO") << endl;
    }
}