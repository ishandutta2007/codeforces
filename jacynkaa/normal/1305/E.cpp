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
const int MAXN = 100 * 1000 * 1000;

bool odwiedzone[MAXN];
bool elementy[MAXN];

vector<int> odp;

int n, m;

int get(int x)
{
    int cnt = 0;
    for (int a : odp)
        if (elementy[x - a])
            cnt++;
    return cnt / 2;
}

void dorzuc(int x)
{
    m -= get(x);
    for (int a : odp)
        odwiedzone[x + a] = true; // && (x != 2 * a))
    elementy[x] = true;
    odp.push_back(x);
}

main()
{
    _upgrade;

    cin >> n >> m;

    int q = 1;
    while (odp.size() < n)
    {
        if (m == 0)
        {
            if (!odwiedzone[q])
                dorzuc(q);
            q++;
            continue;
        }
        if (get(q) <= m)
            dorzuc(q);
        //what(m);
        // what(q);
        //what(get(q));
        q++;
    }
    if (m > 0)
        cout << -1 << endl;
    else
    {
        for (int a : odp)
            cout << a << " ";
        cout << endl;
    }
}