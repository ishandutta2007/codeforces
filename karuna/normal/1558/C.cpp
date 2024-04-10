#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long lint;
typedef pair<int, int> pint;

const int M = 2030;
int n, A[M];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    for (int i = 1; i <= n; i++) {
        if (i % 2 != A[i] % 2) {
            cout << -1 << '\n'; return;
        }
    }
    vector<int> Ans;
    for (int i = n; i >= 3; i -= 2) {
        int p, q;
        for (int j = 1; j <= i; j++) {
            if (A[j] == i) p = j;
            if (A[j] == i - 1) q = j;
        }
        if (p < q) {
            Ans.push_back(p); reverse(A + 1, A + p + 1);
            Ans.push_back(q - 1); reverse(A + 1, A + q);
            Ans.push_back(i); reverse(A + 1, A + 1 + i);
            Ans.push_back(i - q + 2); reverse(A + 1, A + i - q + 3);
            Ans.push_back(i); reverse(A + 1, A + 1 + i);
        }
        else {
            Ans.push_back(p); reverse(A + 1, A + 1 + p);
            Ans.push_back(p - q); reverse(A + 1, A + 1 + p - q);
            Ans.push_back(p); reverse(A + 1, A + 1 + p);
            Ans.push_back(q + 1); reverse(A + 1, A + 1 + 1 + q);
            Ans.push_back(i); reverse(A + 1, A + 1 + i);
        }
    }
    cout << Ans.size() << '\n';
    for (auto x : Ans) cout << x << ' '; cout << '\n';
}
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}