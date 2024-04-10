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

int ile[MAXN];
int N[MAXN];
int odp = 0;
int n, q;
map<pii, int> M;

void solve()
{
    cin >> n;
    rep(i, n)
    {
        cin >> N[i + 1];
        odp += N[i + 1];
    }
    cin >> q;
    rep(i, q)
    {
        int a, b, c;
        cin >> a >> b >> c;

        if (M[{a, b}] != 0)
        {

            ile[M[{a, b}]]--;
            if (ile[M[{a, b}]] < N[M[{a, b}]])
                odp++;

            M[{a, b}] = 0;
        }
        if (c != 0)
        {

            M[{a, b}] = c;
            if (ile[c] < N[c])
                odp--;
            ile[c]++;
        }
        //cerr << c << " " << ile[c] << " " << N[c] << endl;
        cout << odp << endl;
    }
}
main()
{
    _upgrade;
    solve();
}