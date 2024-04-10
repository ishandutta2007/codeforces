#include <iostream>
#include <vector>
#include <bitset>


using namespace std;
#define D(a) \
    do { cout << #a " " << (a) << std::endl; } while(false)
const int mxN = 1e5;
int n, m, p[mxN], h[mxN];
vector<int> adj[mxN];
bitset<mxN> visited;

int traveled(int at) {
    visited[at] = true;
    for (int to : adj[at]) {
        if (!visited[to]) {
            p[at]+=traveled(to);
        }
    }
    return p[at];
}
bool ok;
void check(int at) {
    visited[at] = true;
    int happiness = h[at];
    for (int to : adj[at]) {
        if (!visited[to]) {
            happiness -= h[to];
            if (happiness < 0) {
                ok = false;
                return;
            }
            check(to);
            if (!ok) return;
        }
    }


}
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 0; i < n; ++i) {
            cin >> p[i];
            adj[i].clear();
        }for (int i = 0; i < n; ++i) {
            cin >> h[i];
        }
        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            cin >> u >> v;
            --u, --v;
            adj[u].push_back(v); adj[v].push_back(u);
        }
        visited.reset();
        traveled(0);
        ok = true;
        for (int i = 0; i < n; ++i) {
            h[i] += p[i];
            if (h[i] & 1) {
                ok = false; break;
            }
            h[i] /= 2;
            if (h[i]<0 or h[i]>p[i]) {
                ok = false;
                break;
            }
        }

        if (ok) {
            visited.reset();
            check(0);
        }
        if (ok) cout << "YES" << endl;
        else cout << "NO" << endl;



    }
}