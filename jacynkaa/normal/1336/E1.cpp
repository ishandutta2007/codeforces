#include <bits/stdc++.h>
#include <math.h>
#include <chrono>
using namespace std;
#pragma GCC optimize("-O3")
#define endl "\n"
#define mp make_pair
#define st first
#define nd second
#define pb push_back
#define _upgrade ios_base::sync_with_stdio(0), cout.setf(ios::fixed), cout.precision(10), cin.tie(0), cout.tie(0);
#define cerr \
    if (0)   \
    cerr
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define FWD(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define fwd(i, a, b) for (int i = (a); i < (b); ++i)
#define all(c) (c).begin(), (c).end()
#define sz(X) (int)((X).size())
#define what(x) cerr << #x << " is " << x << endl;
#define int long long
#define repp(i, a, b) for (int i = a; i < (b); ++i)
#define trav(a, x) for (auto &a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MOD = 998244353;
const int SMALL = 13;
const int BIG = 24;

void FST(vi &a, bool inv)
{
    for (int n = sz(a), step = 1; step < n; step *= 2)
    {
        for (int i = 0; i < n; i += 2 * step)
            repp(j, i, i + step)
            {
                int &u = a[j], &v = a[j + step];
                tie(u, v) = pii(u + v, u - v); // XOR /// include-line
            }
    }
    if (inv)
        trav(x, a) x /= sz(a); // XOR only /// include-line
}
vi conv(vi a, vi b)
{
    FST(a, 0);
    FST(b, 0);
    repp(i, 0, sz(a)) a[i] *= b[i];
    FST(a, 1);
    return a;
}

vector<int> X1[BIG];
vector<int> X2[BIG];
long long res[100];

vector<int> get(vector<int> &A)
{
    vector<int> R;
    for (int S = 0; S < (1 << sz(A)); S++)
    {
        int a = 0;
        rep(i, sz(A)) if (S & (1 << i)) a ^= A[i];
        R.push_back(a);
        what(a);
    }
    return R;
}

void fil(vector<int> &R, vector<int> X[BIG])
{
    for (int r : R)
    {
        what(__builtin_popcountll(r >> SMALL));
        what((r & ((1 << SMALL) - 1)));
        X[__builtin_popcountll(r >> SMALL)][r & ((1 << SMALL) - 1)]++;
    }
}

int32_t main()
{
    _upgrade;
    int n, m;
    cin >> n >> m;
    vector<int> A(n);
    sort(all(A));
    set<int> S;
    rep(i, n) cin >> A[i];
    for (int a : A)
    {
        for (auto itr = S.rbegin(); itr != S.rend(); itr++)
            a = min(a, a ^ (*itr));
        if (a)
            S.insert(a);
    }
    cerr << "SET:\n";
    for (int s : S)
        cerr << s << " ";
    cerr << endl;

    rep(i, BIG) X1[i].resize(1 << SMALL);
    rep(i, BIG) X2[i].resize(1 << SMALL);

    vector<int> C1;
    vector<int> C2;
    for (int b : S)
        if (b >= (1 << SMALL))
            C1.push_back(b);
        else
            C2.push_back(b);

    long long pot = 1;
    rep(i, n - sz(S))
        pot = (pot * 2) % MOD;

    auto R1 = get(C1);
    auto R2 = get(C2);
    fil(R1, X1);
    fil(R2, X2);
    rep(i, BIG)
    {
        what(i);
        auto Q = conv(X1[i], X2[0]);
        rep(j, sz(Q)) { res[__builtin_popcountll(j) + i] = (Q[j] + res[__builtin_popcountll(j) + i]) % MOD; }
    }
    rep(i, m + 1) cout << (res[i] * pot) % MOD << " ";
    cout << endl;
}