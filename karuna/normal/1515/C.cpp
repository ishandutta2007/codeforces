#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long lint;
typedef pair<int, int> pint;
typedef pair<lint, lint> plint;
const int MAX = 1e5 + 10;

int A[MAX];
priority_queue<pint> Q;
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, m, x; cin >> n >> m >> x;
        for (int i = 1; i <= m; i++) Q.emplace(0, i);
        for (int i = 1; i <= n; i++) {
            int t; cin >> t;
            auto [d, k] = Q.top(); Q.pop();
            A[i] = k; Q.emplace(d - t, k);
        }
        while (!Q.empty()) Q.pop();
        cout << "YES\n";
        for (int i = 1; i <= n; i++) cout << A[i] << ' ';
        cout << '\n';
    }
}