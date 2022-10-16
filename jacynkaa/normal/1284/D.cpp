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
const int MOD = (long long)(1e9 + 7) * ((int)(1e9 + 9));
int pot3[MAXN];
int n;

void wypisz(set<int> S)
{
    cerr << "tak wyglada set: " << endl;
    for (int a : S)
        cerr << a << " ";
    cerr << endl;
}

vector<int> H(vector<pii> &A)
{
    map<int32_t, vector<int32_t>> M;
    rep(i, n)
    {
        auto P = A[i];
        M[P.st].push_back(i + 1);
        M[P.nd + 1].push_back(-(i + 1));
    }
    bool plus = false;
    int hasz = 0;
    vector<int> odp;
    set<int> S;

    for (auto &V : M)
    {
        //cerr << "ogladam " << V.st << endl;
        sort(all(V.nd));
        for (int a : V.nd)
        {
            if (a < 0)
            {
                if (plus)
                {
                    plus = false;
                    odp.push_back(hasz);
                    // wypisz(S);
                }
                //  S.erase(abs(a));
                hasz = (hasz - pot3[abs(a)] + MOD + MOD) % MOD;
            }
            else
            {
                plus = true;
                hasz = (hasz + pot3[abs(a)] + MOD) % MOD;
                S.insert(abs(a));
            }
        }
    }

    sort(all(odp));
    /*
    cerr << "tak wyglada" << endl;
    for (int a : odp)
        cerr << a << " ";
    cerr << endl;
    */
    return odp;
}

void pre()
{
    rep(i, MAXN)
        pot3[i] = (i == 0) ? 1 : (pot3[i - 1] * 3) % MOD;
}

void solve()
{
    cin >> n;
    vector<pii> A(n);
    auto B = A;
    rep(i, n) cin >> A[i].st >> A[i].nd >> B[i].st >> B[i].nd;
    // /rep(i, n) cin

    auto AA = H(A);
    //cerr << endl;
    auto BB = H(B);

    if (AA == BB)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

main()
{
    _upgrade;
    cerr << MOD << endl;
    pre();
    solve();
}