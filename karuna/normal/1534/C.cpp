#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long lint;
typedef pair<int, int> pint;
const int M = 4e5 + 10;
const int MOD = 1e9 + 7;

int n, A[M], B[M], Dp[M];

struct Dsu {
    int P[M];
    void init() {
        for (int i = 1; i <= n; i++) P[i] = i;
    }
    int Find(int a) {
        return P[a] == a ? a : P[a] = Find(P[a]);
    }
    void Union(int a, int b) {
        P[Find(b)] = Find(a);
    }
    int count() {
        int ret = 0;
        for (int i = 1; i <= n; i++) {
            if (P[i] == i) ++ret;
        }
        return ret;
    }
} D;
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    Dp[0] = 1;
    for (int i = 1; i < M; i++) {
        Dp[i] = Dp[i - 1] * 2 % MOD;
    }
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            int x; cin >> x; A[x] = i;
        }
        for (int j = 1; j <= n; j++) {
            int x; cin >> x; B[x] = j;
        }
        D.init();
        int f = 0;
        for (int i = 1; i <= n; i++) {
            if (A[i] == B[i]) {
                cout << "0\n"; f = 1; break;
            }
        }
        if (f) continue;

        for (int i = 1; i <= n; i++) {
            D.Union(A[i], B[i]);
        }
        int x = D.count();
        cout << Dp[x] << '\n';
    }
}