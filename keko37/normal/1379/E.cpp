#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 100005;

int cnt;
int par[MAXN], br[MAXN];

void solve (int n, int k, int root) {
    if (n == 0) return;
    int curr = ++cnt;
    par[curr] = root;
    if (k == 0) {
        solve((n - 1) / 2, 0, curr);
        solve((n - 1) / 2, 0, curr);
    } else if (k == 1) {
        int pot = 1;
        while (pot <= n) pot *= 2; pot /= 2;
        if (n - pot >= pot / 2) {
            solve(pot - 1, 0, curr);
            solve(n - pot, 1, curr);
        } else {
            solve(pot / 2 - 1, 0, curr);
            solve(n - pot / 2, 1, curr);
        }
    } else {
        if (__builtin_popcount(n - (k - 1) + 1) == 1) {
            solve(1, 0, curr);
            solve(n - 2, k - 1, curr);
        } else {
            solve(n - 1, k - 1, curr);
        }
    }
}

void add_leaves (int n) {
    for (int i = 1; i <= n; i++) br[par[i]]++;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 2 - br[i]; j++) {
            par[++cnt] = i;
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    if (n == 1) {
        if (k == 0) cout << "YES\n" << 0; else cout << "NO";
        return 0;
    }
    if (n % 2 == 0) {
        cout << "NO";
        return 0;
    }
    n = (n - 1) / 2;
    if (n == 3 && k == 1 || n == 4 && k == 2) {
        cout << "NO";
        return 0;
    }
    if (__builtin_popcount(n + 1) == 1) {
        if (k == 1 || k >= n) {
            cout << "NO";
            return 0;
        }
        solve(n, k, 0);
    } else {
        if (k == 0 || k >= n) {
            cout << "NO";
            return 0;
        }
        solve(n, k, 0);
    }
    add_leaves(n);
    cout << "YES\n";
    for (int i = 1; i <= 2*n+1; i++) cout << par[i] << " ";
    return 0;
}