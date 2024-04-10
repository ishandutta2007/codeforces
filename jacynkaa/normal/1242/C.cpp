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
const int MAXK = 15;

vector<int> pudelka[20];
unordered_map<int, int> M;
unordered_map<int, int> visited;
vector<pii> OK[1 << MAXK];
int sum[20];
int Su = 0;
int k;

//vector1.insert( vector1.end(), vector2.begin(), vector2.end() );

int porzadana(int x)
{
    int a = M[x];

    return -sum[a] + Su + x;
}

vector<int> Q;
int mask = 0;
void dfs(int x, int a, int odleglosc)
{
    Q.push_back(x);
    mask = mask | (1 << (M[x] - 1));

    int y = porzadana(x);
    if (M[y] == 0 || odleglosc > k + 2)
    {
        mask = -1;
        return;
    }
    if (y == a)
        return;

    dfs(y, a, odleglosc + 1);
}

void input()
{
    cin >> k;
    rep(i, k)
    {
        int n;
        cin >> n;
        rep(l, n)
        {
            int a;
            cin >> a;
            pudelka[i + 1].push_back(a);
            M[a] = i + 1;
        }
        sum[i + 1] = accumulate(all(pudelka[i + 1]), 0);
        Su += sum[i + 1];
    }
    if ((Su % k) != 0)
    {
        cout << "No" << endl;
        exit(0);
    }
    Su = Su / k;
}

void solve()
{
    rep(S, (1 << k))
    {
        if (OK[S].size() > 0)
            continue;
        for (int Sp = S; Sp > 0; Sp = (Sp - 1) & S)
            if (OK[Sp].size() > 0 && OK[S ^ Sp].size() > 0)
            {
                OK[S] = OK[Sp];
                OK[S].insert(OK[S].end(), OK[S ^ Sp].begin(), OK[S ^ Sp].end());
                break;
            }
    }
    /*
    rep(S, (1 << k))
    {
        what(S);
        cout << OK[S].size() << endl;
    }
    */

    vector<pii> ans(k);
    if (OK[(1 << k) - 1].size() > 0)
    {
        for (auto P : OK[(1 << k) - 1])
            ans[M[P.first] - 1] = P;
        cout << "Yes" << endl;
        for (auto P : ans)
            cout << P.st << " " << P.nd << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}

main()
{
    _upgrade;
    input();
    rep(i, k) for (auto a : pudelka[i + 1])
    {
        if (visited[a] == 0)
        {
            Q.clear();
            mask = 0;
            dfs(a, a, 0);
            /*
            cerr << a << " " << Q.size() << " " << mask << endl;
            for (auto q : Q)
                cerr << q << " ";
            cerr << endl;
            cerr << endl;
            */

            if (mask != -1 && Q.size() == __builtin_popcount(mask) && OK[mask].empty())
            {

                rep(l, Q.size()) { OK[mask].push_back(mp(Q[l], M[Q[(l - 1 + Q.size()) % Q.size()]])); }
            }
        }
    }
    solve();
}