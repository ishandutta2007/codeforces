#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long lint;
typedef pair<int, int> pint;
typedef pair<lint, lint> plint;
const int MAX = 2e5 + 10;

int n, l, r, ans, L[MAX], R[MAX];
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        cin >> n >> l >> r;
        for (int i = 0; i < l; i++) {
            int x; cin >> x; L[x]++;
        }
        for (int i = 0; i < r; i++) {
            int x; cin >> x; R[x]++;
        }
        ans = 0;
        for (int i = 0; i <= n; i++) {
            if (L[i] && R[i]) {
                int k = min(L[i], R[i]);
                L[i] -= k; R[i] -= k; l -= k; r -= k;
            }
        }
        if (l < r) {
            for (int i = 0; i <= n; i++) swap(L[i], R[i]);
            swap(l, r);
        }
        for (int i = 0; i <= n; i++) {
            if (l == r) break;
            if (L[i] >= 2) {
                L[i] -= 2; ans++; l -= 2; --i;
            }
        }
        cout << ans + l << '\n';
        ans = 0;
        for (int i = 0; i <= n; i++) L[i] = R[i] = 0;
    }
}