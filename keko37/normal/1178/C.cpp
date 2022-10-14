#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

const int MAXN = 100005;
const int MOD = 998244353;

llint n, m, sol = 1;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i=0; i<n; i++) sol = (sol * 2) % MOD;
    for (int i=0; i<m; i++) sol = (sol * 2) % MOD;
    cout << sol;
    return 0;
}