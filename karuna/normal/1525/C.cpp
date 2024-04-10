#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long lint;
typedef pair<int, int> pint;
const int M = 3e5 + 10;

int t, n, m, Ans[M];
pair<pint, int> A[M];
vector<pint> O, E;
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) cin >> A[i].va.va;
        for (int i = 1; i <= n; i++) {
            char c; cin >> c;
            if (c == 'R') A[i].va.vb = 1;
            else A[i].va.vb = 0;
            A[i].vb = i;
        }
        for (int i = 1; i <= n; i++) Ans[i] = -1;
        sort(A + 1, A + 1 + n);
        for (int i = 1; i <= n; i++) {
            vector<pint> &V = (A[i].va.va % 2 == 0 ? E : O);
            if (A[i].va.vb == 0) {
                if (!V.empty()) {
                    auto [x, k] = V.back(); V.pop_back();
                    Ans[k] = Ans[A[i].vb] = (A[i].va.va - x) / 2;
                }
                else {
                    V.emplace_back(-A[i].va.va, A[i].vb);
                }
            }
            else V.emplace_back(A[i].va.va, A[i].vb);
        }
        while (E.size() >= 2) {
            auto [x, k] = E[E.size() - 2];
            auto [y, l] = E.back();
            Ans[k] = Ans[l] = (2 * m - y - x) / 2;
            E.pop_back(); E.pop_back();
        }
        while (O.size() >= 2) {
            auto [x, k] = O[O.size() - 2];
            auto [y, l] = O.back();
            Ans[k] = Ans[l] = (2 * m - y - x) / 2;
            O.pop_back(); O.pop_back();
        }
        for (int i = 1; i <= n; i++) {
            cout << Ans[i] << ' ';
        }
        cout << '\n';
        O.clear(); E.clear();
    }
}