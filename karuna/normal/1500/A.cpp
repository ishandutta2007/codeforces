#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long lint;
typedef pair<int, int> pint;
typedef pair<lint, lint> plint;
const int MAX = 2e5 + 10;

int n;
pint A[MAX], C[5000050];
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> A[i].va, A[i].vb = i;
    sort(A + 1, A + 1 + n);

    vector<pint> T, F;
    for (int i = 1, p = 0; i <= n;) {
        p = i;
        while (p <= n && A[p].va == A[i].va) ++p;
        if (p - i >= 4) { for (int j = i; j < i + 4; j++) F.push_back(A[j]); break; }
        if (p - i >= 2) {
            T.push_back(A[i]); T.push_back(A[i + 1]);
            if (T.size() == 4) break;
        }
        i = p;
    }
    if (F.size() == 4) {
        cout << "YES\n";
        for (auto x : F) cout << x.vb << ' ';
        return 0;
    }
    if (T.size() == 4) {
        cout << "YES\n";
        cout << T[0].vb << ' ' << T[2].vb << ' ' << T[1].vb << ' ' << T[3].vb;
        return 0;
    }

    for (int i = 1; i <= n; i++) for (int j = i + 1; j <= n; j++) {
        if (T.size() == 2 && (A[i].va == T[0].va || A[j].va == T[0].va)) continue;
        int x = A[i].va + A[j].va;
        if (C[x].va != 0) {
            cout << "YES\n";
            cout << C[x].va << ' ' << C[x].vb << ' ' << A[i].vb << ' ' << A[j].vb;
            return 0;
        }
        C[x] = { A[i].vb, A[j].vb };
    }
    if (T.size() == 2) {
        int x = T[0].va;
        for (int i = 1; i <= n; i++) {
            if (A[i].va == x) continue;
            if (C[x + A[i].va].va != 0) {
                cout << "YES\n";
                cout << C[x + A[i].va].va << ' ' << C[x + A[i].va].vb << ' ' << T[0].vb << ' ' << A[i].vb;
                return 0;
            }
        }
        if (C[2 * x].va != 0) {
            cout << "YES\n";
            cout << C[2 * x].va << ' ' << C[2 * x].vb << ' ' << T[0].vb << ' ' << T[1].vb;
            return 0;
        }
    }
    cout << "NO";
}