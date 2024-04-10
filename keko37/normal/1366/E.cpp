#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 200005;
const int MOD = 998244353;

int n, m, sol = 1;
int a[MAXN], b[MAXN];

int mul (int x, int y) {return (llint) x * y % MOD;}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    int pos = n-1;
    for (int i = m-1; i >= 0; i--) {
        while (pos >= 0 && a[pos] > b[i]) pos--;
        if (pos < 0 || a[pos] != b[i]) {
            cout << 0;
            return 0;
        }
        int x = 0;
        while (pos >= 0 && a[pos] >= b[i]) pos--, x++;
        if (i > 0) sol = mul(sol, x);
    }
    if (pos >= 0) {
        cout << 0;
        return 0;
    }
    cout << sol;
    return 0;
}