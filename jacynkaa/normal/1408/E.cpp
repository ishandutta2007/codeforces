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

const int MAXN = 1e6;
const int MAXS = 3e5;
int kapitan[MAXN];
int A[MAXN];
int B[MAXN];

int find(int x)
{
    return kapitan[x] == x ? x : kapitan[x] = find(kapitan[x]);
}
bool unia(int a, int b)
{
    int y = find(a);
    int x = find(b);
    kapitan[x] = y;
    return x != y;
}

int32_t main()
{
    _upgrade;
    rep(i, MAXN)
        kapitan[i] = i;
    int n, m;

    cin >> m >> n;
    rep(i, m) cin >> A[i];
    rep(i, n) cin >> B[i];
    priority_queue<pair<int, pii>> Q;
    int sum = 0;
    rep(i, m)
    {
        int s;
        cin >> s;
        rep(j, s)
        {
            int a;
            cin >> a;
            --a;
            int cost = A[i] + B[a];
            sum += cost;
            Q.push({cost, {i, a + MAXS}});
        }
    }
    while (!Q.empty())
    {
        auto q = Q.top();
        Q.pop();
        if (unia(q.nd.st, q.nd.nd))
            sum -= q.st;
    }
    cout << sum << endl;
}