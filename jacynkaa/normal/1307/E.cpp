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
const int MAXN = 5005;
const int MOD = 1000 * 1000 * 1000 + 7;

int krowy[MAXN][MAXN];
bool jest[MAXN][MAXN];
int lef[MAXN];
int rig[MAXN];
int sweet[MAXN];
int INV[MAXN * MAXN]; //?
int n, m;

void input()
{
    cin >> n >> m;
    rep(i, n)
    {
        cin >> sweet[i];
        sweet[i]--;
    }
    rep(i, m)
    {
        int a, b;
        cin >> a >> b;
        --a;
        krowy[a][b]++;
        jest[a][b] = true;
    }
    rep(i, MAXN) rep(j, MAXN) if (j != 0) krowy[i][j] += krowy[i][j - 1];
    /*
    rep(i, n)
    {
        rep(j, n)
                cerr
            << krowy[i][j] << " ";
        cerr << endl;
    }
    */
}

void clear()
{
    rep(i, MAXN)
        lef[i] = rig[i] = 0;
}

pii get(int x)
{
    int a = lef[x];
    int b = rig[x];
    if (a > b)
        swap(a, b);
    if (krowy[x][b] == 0)
        return make_pair(0, 1);

    if (krowy[x][a] == 0)
        return make_pair(1, krowy[x][b]);

    if (krowy[x][b] == 1)
        return make_pair(1, 2); //??????

    return make_pair(2, (krowy[x][b] - 1) * krowy[x][a]);
}

pii compose(pii A, pii B)
{
    return make_pair(A.st + B.st, ((long long)A.nd * (long long)B.nd) % MOD);
}

pii solve(int q = 0)
{
    pii odp = {-1, -1};
    for (int i = 0; i + q <= n; i++)
    {
        clear();
        for (int l = 0; l < i; l++)
            lef[sweet[l]]++;
        for (int l = i + q; l < n; l++)
            rig[sweet[l]]++;

        pii tmp = {0, 1};
        rep(l, n)
        {
            //cerr << " ( " << rig[l] << ", " << lef[l] << ": " << get(l).st << ", " << get(l).nd << " ) ";
            tmp = compose(tmp, get(l));
            //cerr << get(l).st << " " << get(l).nd << endl;
        }
        //cerr << endl;
        if (tmp.st == odp.st)
            odp.nd = (odp.nd + tmp.nd) % MOD;
        else
            odp = max(odp, tmp);
    }
    return odp;
}

main()
{
    _upgrade;
    input();
    auto P1 = solve(0);
    //cerr << "pary\n";
    auto P2 = solve(1);
    cout << P1.st << " ";
    if (P1.st == P2.st)
        cout << (P1.nd - P2.nd + MOD) % MOD << endl;
    else
        cout << P1.nd << endl;
}