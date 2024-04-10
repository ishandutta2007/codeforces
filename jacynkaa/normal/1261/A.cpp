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

vector<pii> odp;
string S;
int n, k;

int F(char c, int pos)
{
    for (int i = pos; i < n; i++)
        if (S[i] == c)
            return i;
    return -22;
}

void zachlan(int pos)
{
    if (pos % 2)
    {
        k--;
        int q = F(')', pos);
        if (q != pos)
        {
            odp.push_back({pos, q});
            reverse(S.begin() + pos, S.begin() + q + 1); //uwaga
        }
    }
    else
    {
        int q = F('(', pos);
        if (q != pos)
        {
            odp.push_back({pos, q});
            reverse(S.begin() + pos, S.begin() + q + 1); //uwaga
        }
    }
}
void rac(int pos)
{
    int q = F('(', pos);
    if (q == -22)
        return;
    else
    {
        if (q != pos)
        {
            odp.push_back({pos, q});
            reverse(S.begin() + pos, S.begin() + q + 1); //uwaga
        }
    }
}

void solve()
{
    rep(i, n)
    {
        if (k != 1)
            zachlan(i);
        else
            rac(i);
    }
}

main()
{

    _upgrade;
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        cin >> S;
        solve();
        cout << odp.size() << endl;
        for (auto P : odp)
            cout << P.st + 1 << " " << P.nd + 1 << endl;
        cerr << S << endl;
        odp.clear();
    }
}