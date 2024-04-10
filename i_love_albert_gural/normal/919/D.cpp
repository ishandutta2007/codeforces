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

int ct[300000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N, M;
    cin >> N >> M;

    string vals;
    cin >> vals;

    vi ind(N);
    vvi adj(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        adj[u-1].push_back(v-1);
        ind[v-1]++;
    }

    queue<int> dudu;
    for (int i = 0; i < N; i++) {
        if (ind[i] == 0)
            dudu.push(i);
    }

    vi topo;
    while (!dudu.empty()) {
        int loc = dudu.front();
        dudu.pop();
        topo.push_back(loc);

        for (int nbr : adj[loc]) {
            if (--ind[nbr] == 0)
                dudu.push(nbr);
        }
    }

    if (topo.size() != N) {
        cout << -1 << endl;
        return 0;
    }

    reverse(all(topo));

    int ans = 0;
    for (char let = 'a'; let <= 'z'; let++) {
        vi dp(N);
        for (int loc : topo) {
            for (int nbr : adj[loc]) {
                dp[loc] = max(dp[loc], dp[nbr]);
            }
            if (vals[loc] == let)
                dp[loc]++;
            ans = max(ans, dp[loc]);
        }
    }

    cout << ans << endl;
    return 0;
}