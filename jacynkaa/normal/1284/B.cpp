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
const int MAXN = 2e5;

int tab[MAXN];
int maks[MAXN];
int mini[MAXN];
vector<int> T[MAXN];
vector<int> nieok;
vector<int> maksy;
long long odp;

bool des(vector<int> &A)
{
    rep(i, (int)A.size() - 1) if (A[i + 1] > A[i]) return true;
    return false;
}

main()
{
    _upgrade;
    int n;
    cin >> n;
    rep(i, n)
    {
        int l;
        cin >> l;
        T[i].resize(l);
        rep(j, l) cin >> T[i][j];
        if (des(T[i]) == false)
            nieok.push_back(i);
    }
    for (int a : nieok)
    {
        mini[a] = *min_element(all(T[a]));
        maks[a] = *max_element(all(T[a]));
        maksy.push_back(maks[a]);
    }
    sort(all(maksy));
    for (int a : nieok)
    {
        odp += (upper_bound(all(maksy), mini[a]) - maksy.begin());
    }
    cout << n * n - odp << endl;
}