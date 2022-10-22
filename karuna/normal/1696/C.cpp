#include <bits/stdc++.h>
using namespace std;

int n, m, k;

void func(vector<int> &A, vector<pair<int, long long>> &Res) {
    for (int i = 0; i < A.size(); i++) {
        int x = A[i], c = 1;
        while (x % m == 0) {
            c *= m; x /= m;
        }
        if (!Res.empty() && Res.back().first == x) {
            Res.back().second += c;
        }
        else Res.emplace_back(x, c);        
    }

}
void solve() {
    cin >> n >> m;
    vector<int> A(n); for (int i = 0; i < n; i++) cin >> A[i];
    cin >> k;
    vector<int> B(k); for (int i = 0; i < k; i++) cin >> B[i];

    vector<pair<int, long long>> Ra, Rb;
    func(A, Ra); func(B, Rb);

    if (Ra.size() != Rb.size()) {
        cout << "No\n"; return;
    }
    for (int i = 0; i < Ra.size(); i++) {
        if (Ra[i] != Rb[i]) {
            cout << "No\n"; return;
        }
    }
    cout << "Yes\n";
}
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}