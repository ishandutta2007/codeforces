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

const int W = 2000;
const int MAXN = 3e5;
int ne[MAXN];
int SZ[MAXN];
int SJ[MAXN];
long long odp = 0;

vector<int> X;
string S;
int n;

void debug()
{
    cerr << S << endl;
    rep(i, n)
    {
        what(i);
        what(ne[i]);
        what(SZ[i]);
        what(SJ[i]);
        cerr << endl;
    }
}

void pre()
{
    int a = n;
    for (int k = n - 1; k >= 0; k--)
    {
        ne[k] = a;
        if (S[k] == '1')
            a = k;
    }

    SJ[0] = (S[0] == '1') ? 1 : 0;
    SZ[0] = 1 - SJ[0];
    rep(i, n - 1)
    {
        SJ[i + 1] = SJ[i];
        SZ[i + 1] = SZ[i];
        if (S[i + 1] == '0')
            SZ[i + 1]++;
        else
            SJ[i + 1]++;
    }
}

void brut()
{
    rep(i, n)
    {
        int j = (S[i] == '1') ? i : ne[i];
        int ile = 1;
        while (ile < W && j < n)
        {
            odp += (((ne[j] - i) / ile) - ((j - i) / ile));
            ile++;
            j = ne[j];
        }
    }
}
int val(int k, pii P)
{
    return P.st * k - P.nd;
}

void solve(int k)
{
    // what(k);
    queue<pii> Q;
    Q.push({0, 0});
    unordered_map<int, int> M;
    rep(i, n)
    {
        while (Q.front().st + W <= SJ[i])
        {
            auto P = Q.front();
            if (k == 1)
                cerr << val(k, P) << endl;
            M[val(k, P)]++;
            Q.pop();
        }
        odp += M[val(k, {SJ[i], SZ[i]})];
        Q.push({SJ[i], SZ[i]});
    }
}

void test()
{
    S.clear();
    rep(i, 20000)
        S.push_back('1');
}

main()
{
    _upgrade;
    cin >> S;
    //test();
    n = S.size();
    pre();
    brut();
    //cout << odp << endl;
    for (int i = 0; i <= n / W + 2; i++)
        solve(i);

    // debug();

    cout << odp << endl;
}