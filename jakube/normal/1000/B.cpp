#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, M;
    cin >> n >> M;
    vector<int> v(n + 2);
    v[0] = 0;
    v[n+1] = M;
    for (int i = 0; i < n; i++) {
        cin >> v[i + 1];
    }

    int lit = 0;
    int last = 0;
    for (int i = 1; i <= n + 1; i++) {
        if (i % 2)
            lit += v[i] - last;
        last = v[i];
    }

    int best_lit = lit;
    int fixed = 0;
    last = 0;
    for (int i = 1; i <= n + 1; i++) {
        if (i & 1) {
            fixed += v[i] - last - 1;
            lit -= v[i] - last - 1;
            if (v[i-1] != v[i] - 1) {
                best_lit = max(best_lit, fixed + (M - (v[i] - 1) - lit));
            }
            fixed++;
            lit--;
            if (i < n + 1 && v[i] + 1 != v[i+1]) {
                best_lit = max(best_lit, fixed + (M - (v[i] + 1) - lit));
            }
        }
        last = v[i];
    }
    cout << best_lit << '\n';
}