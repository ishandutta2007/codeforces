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

bool isprime(int x)
{
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0)
            return false;
    return true;
}

const int MASQ = 500;

vector<int> P;

void pre()
{
    for (int i = 2; i < MASQ; i++)
        if (isprime(i))
            P.push_back(i);
    rep(i, 10) cerr << P[i] << endl;
}

int pw(int a, int b)
{
    int res = 1;
    rep(i, b) res *= a;
    return res;
}

int32_t main()
{
    _upgrade;
    int n;
    cin >> n;

    pre();

    vector<int> A(n);

    rep(i, n) cin >> A[i];

    unordered_map<int, vector<int>> M;

    for (int a : A)
    {
        for (int p : P)
        {
            if (a % p == 0)
            {
                int j = 0;
                while (a % p == 0)
                {
                    j++;
                    a /= p;
                }
                M[p].push_back(j);
            }
        }
        if (a > 1)
            M[a].push_back(1);
    }

    int res = 1;
    for (auto p : M)
    {
        sort(all(p.nd));
        if (p.nd.size() == n)
            res *= pw(p.st, p.nd[1]);
        if (p.nd.size() == n - 1)
            res *= pw(p.st, p.nd[0]);
    }
    cout << res << endl;
}