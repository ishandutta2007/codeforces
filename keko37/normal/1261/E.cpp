#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

const int MAXN = 1005;

int n;
int a[MAXN], sol[MAXN][MAXN];

void ispis () {
    cout << n + 1 << '\n';
    for (int i = 0; i < n+1; i++) {
        for (int j = 0; j < n; j++) {
            cout << sol[i][j];
        }
        cout << '\n';
    }
}

void solve (int lo, int hi, int ll, int rr) {
    if (lo == hi) return;
    int val = min(hi - lo, a[ll]);
    for (int i = lo; i < lo + val; i++) {
        sol[i][ll] = 1;
    }
    a[ll] -= val;
    for (int i = 0; i <= n; i++) {
        if (lo <= i && i <= hi) continue;
        if (a[ll] == 0) break; else a[ll]--;
        sol[i][ll] = 1;
    }
    solve(lo, lo + val - 1, ll + 1, ll + val - 1);
    solve(lo + val, hi, ll + val, rr);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    solve(0, n, 0, n - 1);
    ispis();
    return 0;
}