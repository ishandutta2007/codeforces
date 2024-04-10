#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long lint;
typedef pair<int, int> pint;

const int N = 16, M = 1 << N;

int n, D[M], Per[M], Inv[M], Col[M];
vector<int> G[M];

void solve() {
    cin >> n;
    for (int i = 0; i < (1 << n); i++) G[i].clear();
    for (int i = 0; i < n * (1 << n - 1); i++) {
        int x, y; cin >> x >> y;
        G[x].push_back(y); G[y].push_back(x);
    }
    queue<int> Q; Q.push(0); 
    for (int i = 1; i < (1 << n); i++) {
        D[i] = -1; Per[i] = 0;
    }
    for (int i = 0; i < n; i++) Per[G[0][i]] = 1 << i;
    while (!Q.empty()) {
        int x = Q.front(); Q.pop();
        for (int y : G[x]) {
            if (D[y] == -1) D[y] = D[x] + 1, Q.push(y);
            if (D[y] > D[x]) Per[y] |= Per[x];
        }
    }
    for (int i = 0; i < (1 << n); i++) {
        Inv[Per[i]] = i;
        for (int j = 0; j < n; j++) if (i >> j & 1) {
            Col[i] = (Col[i ^ (1 << j)] ^ j) % n; break;
        }
    }
    for (int i = 0; i < (1 << n); i++) cout << Inv[i] << ' '; cout << '\n';
    if (n == 1 || n == 2 || n == 4 || n == 8 || n == 16) {
        for (int i = 0; i < (1 << n); i++) {
            cout << Col[Per[i]] << ' ';
        }
        cout << '\n';
    }
    else cout << "-1\n";

}
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}