#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long lint;
typedef pair<int, int> pint;

const int M = 3e5 + 10;
int n, m, A[M], B[M], Chk[M];

struct Dsu {
    int Par[M];
    
    void init() {
        for (int i = 1; i <= n; i++) {
            Par[i] = i;
        }
    }
    int Find(int a) {
        return Par[a] = Par[a] == a ? a : Find(Par[a]);
    }
    void Union(int a, int b) {
        Par[Find(b)] = Find(a);
    }
} D;
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) B[i] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        B[(i - A[i] + n) % n] += 1;
    }
    vector<int> V;
    for (int i = 0; i < n; i++) {
        if (3 * B[i] < n) continue;
        D.init();

        int ans = 0;
        for (int j = 1; j <= n; j++) {
            if (D.Find(A[j]) == D.Find((j - i + n - 1) % n + 1)) continue;
            D.Union(A[j], (j - i + n - 1) % n + 1); ans += 1;
        }
        if (ans <= m) V.push_back(i);
    }
    sort(V.begin(), V.end());
    cout << V.size() << ' ';
    for (int x : V) cout << x << ' ';
    cout << '\n';
}
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}