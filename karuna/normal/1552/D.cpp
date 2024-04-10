#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long lint;
typedef pair<int, int> pint;

void solve() {
    int n, A[11];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i]; A[i] = abs(A[i]);
    }

    vector<int> V;
    for (int i = 0; i < (1 << n); i++) {
        int s = 0;
        for (int j = 0; j < n; j++) if (i >> j & 1) {
            s += A[j];
        }
        V.push_back(s);
    }
    sort(V.begin(), V.end());
    int f = 0;
    for (int i = 1; i < V.size(); i++) {
        if (V[i] == V[i - 1]) f = 1;
    }
    cout << (f == 1 ? "YES\n" : "NO\n");
}
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}