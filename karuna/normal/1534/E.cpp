#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long lint;
typedef pair<int, int> pint;
const int M = 510;

int n, k, A[M];
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> n >> k;
    if ((n & 1) && (~k & 1)) {
        cout << "-1" << endl; return 0;
    }
    int d = 0, x = 0;
    for (int i = 1; i < M; i++) {
        int x = i * k;
        if (n > x) continue;
        if ((x - n) % 2 == 1) continue;
        if (n * (i - (~i & 1)) < x) continue;
        d = i; break;
    }
    x = d * k;
    for (int i = 1; i <= n; i++) {
        A[i] = 1; --x;
    }
    x /= 2;
    int q = x / n;
    for (int i = 1; i <= n; i++) {
        if (x % (n - i + 1) == 0) A[i] += 2 * q, x -= q;
        else A[i] += 2 * (q + 1), x -= q + 1;
    }
    int ans = 0, p = 0;
    priority_queue<pint> Q;
    for (int i = 1; i <= n; i++) {
        Q.emplace(A[i], i);
    }
    for (int i = 1; i <= d; i++) {
        cout << "? ";
        vector<pint> V;
        while (!Q.empty() && V.size() < k) {
            auto [a, b] = Q.top(); Q.pop();
            V.emplace_back(a, b);
        }
        for (auto [a, b] : V) {
            Q.emplace(a - 1, b);
            cout << b << ' ';
        }
        cout << endl;

        int x; cin >> x; ans ^= x;
    }
    cout << "! " << ans << endl;
}