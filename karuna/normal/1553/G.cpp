#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long lint;
typedef pair<int, int> pint;

const int M = 1e6 + 10, N = 2e5 + 10;

int n, q, A[N], P[M] = { 1, 1 }, Chk[M];
vector<int> Primes, V[M], B[N];

struct Dsu {
    int Par[N << 1];

    void init() {
        iota(Par, Par + (N << 1), 0);
    }
    int Find(int a) {
        return Par[a] = (Par[a] == a ? a : Find(Par[a]));
    }
    void Union(int a, int b) {
        Par[Find(b)] = Find(a);
    }
} D;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> A[i]; Chk[A[i]] = i;
    }
    for (int i = 2; i < M; i++) {
        if (P[i]) continue; Primes.push_back(i);
        for (int j = 2 * i; j < M; j += i) P[j] = 1;
    }
    int sz = Primes.size(); D.init();
    for (int i = 0; i < sz; i++) {
        int p = Primes[i];
        for (int j = p; j < M; j += p) {
            V[j].push_back(i);
            if (Chk[j]) D.Union(i, sz + Chk[j]); 
        }
    }
    for (int i = 1; i <= n; i++) {
        int x = D.Find(sz + i);
        vector<int> X = V[A[i] + 1]; 
        for (int i = 0; i < X.size(); i++) {
            X[i] = D.Find(X[i]); 
        } X.push_back(x);

        sort(X.begin(), X.end());
        X.erase(unique(X.begin(), X.end()), X.end());
        for (int i = 0; i < X.size(); i++) {
            for (int j = 0; j < X.size(); j++) if (i != j) {
                B[X[i]].push_back(X[j]);
            }
        }
    }
    for (int i = 0; i < Primes.size(); i++) {
        sort(B[i].begin(), B[i].end());
    }
    while (q--) {
        int a, b; cin >> a >> b;
        if (D.Find(sz + a) == D.Find(sz + b)) {
            cout << 0 << '\n'; continue;
        }
        if (D.Find(sz + a) == 0 || D.Find(sz + b) == 0) {
            cout << 1 << '\n'; continue;
        }
        a = D.Find(sz + a); b = D.Find(sz + b);

        auto it = lower_bound(B[a].begin(), B[a].end(), b);
        if (it != B[a].end() && *it == b) cout << 1 << '\n';
        else cout << 2 << '\n';
    }
}