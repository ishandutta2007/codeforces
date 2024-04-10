#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<
#define pb push_back
#define fi first
#define se second
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define TRACE(x) cerr << #x << "  " << x << endl
template<typename T1, typename T2>inline void minaj(T1 &x, T2 y) { x = (x > y ? y: x);}
template<typename T1, typename T2>inline void maxaj(T1 &x, T2 y) { x = (x < y ? y: x);}

typedef double lf;
typedef long long ll;
typedef pair<int, int> pii;

const int mod = 998244353;
int add(int x, int y) {x += y; if(x >= mod) return x - mod; return x;}
void addaj(int &x, int y) {x += y; if(x >= mod) x -= mod;}
int sub(int x, int y) {x -= y; if(x < 0) return x + mod; return x;}
void subaj(int &x, int y) {x -= y; if(x < 0) x += mod;}
int mul(int x, int y) {return (ll) x * y % mod;}

const int MAXN = 2e5 + 5;

vector<int> in[MAXN];
vector<int> out[MAXN];

map<int, int> veza[MAXN];

int cost[MAXN];
int best[MAXN];

int main() {
    int n, m; cin >> n >> m;

    REP(i, m) {
        int u, v; cin >> u >> v;
        out[u].push_back(v);
        in[v].push_back(u);
        cost[u] ++;
    }

    set<pii> dijkstra;
    dijkstra.insert({0, n});

    best[n] = 0;
    REP(i, n) best[i] = 1e9;

    vector<int> bio(n + 1);

    while (dijkstra.size()) {
        auto X = dijkstra.begin();
        int x = (*X).second;
        int len = (*X).first;

        dijkstra.erase(X);

        if (bio[x]) continue;
        bio[x] = 1;
        best[x] = len;

        for (auto y : in[x]) {
            cost[y] --;
            int tmp = len + 1 + cost[y];
            dijkstra.insert({tmp, y});
        }
    }

    cout << best[1] << endl;

}