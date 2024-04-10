#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define va first
#define vb second
using namespace std;
typedef long long lint;
typedef pair<int, int> pint;

const int M = 3e5 + 10;
int n, A[M];
// vector<lint> X, Y;

struct Seg {
    lint T[M];

    void update(int a, int x) {
        for (; a < M; a += a & -a) T[a] += x;
    }
    lint query(int a, int b) {
        lint ret = 0;
        for (; b; b -= b & -b) ret += T[b];
        for (--a; a; a -= a & -a) ret -= T[a];
        return ret;
    }
} S, T;

/* void naive() {
    lint ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            ans += (A[j] % A[i]) + (A[i] % A[j]);
        }
        X.push_back(ans);
    }
    cout << '\n';
} */
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    /* freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); */

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> A[i];

    // naive();

    lint ans = 0;
    for (int i = 1; i <= n; i++) {
        int x = A[i];
        ans += T.query(1, x - 1) + S.query(x + 1, M - 1) * x;

        int sq = 1, k = 0;
        while ((sq + 1) * (sq + 1) <= x) sq += 1;

        for (int i = 1; i * (i + 1) <= x; i++) {
            if (S.query(i, i) == 1) ans += x % i;
        }
        ans += x * S.query((x + sq + 1) / (sq + 1), x);
        for (int i = 1; i <= sq; i++) {
            ans -= T.query((x + i + 1) / (i + 1), x / i) * i;
        }

        for (int j = x; j < M; j += x) {
            ans += T.query(j, min(M - 1, j + x - 1)) - S.query(j, min(M - 1, j + x - 1)) * j;
        }
        S.update(x, 1); T.update(x, x);

        cout << ans << ' '; //Y.push_back(ans);
    }
/* 
    for (int i = 0; i < n; i++) {
        if (X[i] != Y[i]) {
            cout << "At " << i << ", " << X[i] << ' ' << Y[i] << '\n';
        }
        else if (i % 10 == 0) cout << X[i] << ' ' << Y[i] << '\n';
    } */
}