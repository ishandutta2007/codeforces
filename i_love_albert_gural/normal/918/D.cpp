#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

bool win[100][100][27][2];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N, M;
    cin >> N >> M;

    vector<vector<pair<int, int>>> adj(N);
    vector<int> ind(N);

    for (int i = 0; i < M; i++) {
        int u, v;
        char c;
        cin >> u >> v >> c;

        adj[u - 1].emplace_back(v - 1, c - 'a' + 1);
        ind[v - 1]++;
    }

    queue<int> sinks;
    for (int i = 0; i < N; i++)
        if (ind[i] == 0) 
            sinks.push(i);

    vector<int> topo;
    while (!sinks.empty()) {
        int loc = sinks.front();
        sinks.pop();

        topo.push_back(loc);
        for (auto e : adj[loc]) {
            if (--ind[e.first] == 0)
                sinks.push(e.first);
        }
    }

    reverse(all(topo));

    for (int l1 : topo) {
        for (int l2 : topo) {
            for (auto e : adj[l1]) {
                for (int lc = 0; lc <= e.second; lc++) {
                    win[l1][l2][lc][0] |= !win[e.first][l2][e.second][1];
                }
            }
            for (auto e : adj[l2]) {
                for (int lc = 0; lc <= e.second; lc++) {
                    win[l1][l2][lc][1] |= !win[l1][e.first][e.second][0];
                }
            }
        }
    }

    for (int l1 = 0; l1 < N; l1++) {
        for (int l2 = 0; l2 < N; l2++) {
            if (win[l1][l2][0][0])
                cout << 'A';
            else
                cout << 'B';
        }
        cout << "\n";
    }

    return 0;
}