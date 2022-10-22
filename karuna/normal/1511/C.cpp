#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long lint;
typedef pair<int, int> pint;
typedef pair<lint, lint> plint;
const int MAX = 3e5 + 10;

int n, q, A[MAX], P[MAX];
vector<int> V;
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> n >> q;
    for (int i = 1; i <= 50; i++) P[i] = 1000000;
    for (int i = 1; i <= n; i++) cin >> A[i], P[A[i]] = min(P[A[i]], i);
    for (int i = 0; i < q; i++) {
        int x; cin >> x;
        auto it = find(V.begin(), V.end(), x);
        if (it == V.end()) {
            cout << P[x]; V.push_back(x);
            for (int i = 1; i <= 50; i++) {
                if (P[i] != 0 && P[i] < P[x]) P[i]++;
            }
            P[x] = 0;
        }
        else {
            cout << V.end() - it; V.erase(it, it + 1);
            V.push_back(x);
        }
        cout << '\n';
    }
}