#include<bits/stdc++.h>

using namespace std;

const int MAXN = 100005;
const int MOD = 1000000007;

int n, m;
int f[MAXN];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    f[0] = f[1] = 1;
    for (int i = 2; i <= max(n, m); i++) {
        f[i] = (f[i - 1] + f[i - 2]) % MOD;
    }
    cout << ((f[n] * 2 % MOD + f[m] * 2 % MOD) % MOD + MOD - 2) % MOD;
    return 0;
}