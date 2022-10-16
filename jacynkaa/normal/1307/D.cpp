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

const int MAXN = 3e5;
const int inf = (int)1e9;

int n, m, k;
vector<int> G[MAXN];
vector<int> A;

vector<int> shortest(int s)
{
    vector<int> dist(n, inf);
    vector<bool> visited(n);
    auto Q = priority_queue<pii>();
    dist[s] = 0;
    Q.push({0, s});
    while (!Q.empty())
    {
        int x = Q.top().nd;
        auto R = Q.top();

        Q.pop();
        if (!visited[x])
        {
            dist[x] = abs(R.st);
            // cerr<<"ogladam: "<<x<<" "<<dist[x]<<endl;
            visited[x] = true;
            for (auto B : G[x])
            {
                //cerr<<"edge: "<<B.st<<" "<<B.nd<<endl;
                // cerr<<"dorzucam: "<<(dist[x]+B.nd)<<" "<<B.st<<endl;
                Q.push({-(dist[x] + 1), B});
            }
        }
    }
    return dist;
}

void input()
{
    cin >> n >> m >> k;
    A.resize(k);
    rep(i, k)
    {
        cin >> A[i];
        A[i]--;
    }
    rep(i, m)
    {
        int a, b;
        cin >> a >> b;
        G[--a].push_back(--b);
        G[b].push_back(a);
    }
}

int get(vector<int> &C, vector<int> &B)
{
    vector<pii> L;
    for (int a : A)
        L.push_back({C[a] - B[a], a});
    sort(all(L), greater<pii>());

    int mak = -inf;
    int odp = -inf;
    for (pii P : L)
    {
        // cerr << P.nd << " ";
        odp = max(odp, C[P.nd] + mak + 1);
        mak = max(mak, B[P.nd]);
    }
    //  cerr << endl;
    return odp;
}

void solve()
{
    vector<int> C = shortest(0);
    vector<int> B = shortest(n - 1);
    int dist = 0;
    dist = max(dist, get(C, B));
    dist = max(dist, get(B, C));
    cout << min(dist, B[0]) << endl;
}

main()
{
    _upgrade;
    input();
    solve();
}