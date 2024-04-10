#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

typedef long long llint;

const int MOD = 1000000007;

int n, m, x;
vector < vector <int> > dp[350];

int f (int pos, int a, int b) {
    if (a>n || b>n) return 0;
    if (pos == m) {
        if (a == 0 && b == n) return 1;
        return 0;
    }
    if (dp[a] [b] [pos] !=-1) return dp[a] [b] [pos];
    llint res = 0;
    if (pos != x-1) {
        res += f(pos+1, a, b);  // nista nista
        if (a>0) res += f(pos+1, a-1, b+1);  // nista zatvori
    }
    res += f(pos+1, a+1, b);  // otvori nista
    res += f(pos+1, a, b+1);  // otvori zatvori
    while (res>=MOD) res -= MOD;
    dp[a] [b] [pos] = res;
    return res;
}

llint fact (llint br) {
    if (br == 1) return 1;
    return br * fact(br-1) % MOD;
}

void precompute () {
    vector <int> e;
    for (int i=0; i<m; i++) e.push_back(-1);
    for (int i=0; i<n+1; i++) dp[0].push_back(e);
    for (int i=0; i<n+1; i++) dp[i] = dp[0];

}

int main () {
    cin >> n >> m >> x;
    if (n>m) {
        cout << 0;
        return 0;
    }
    precompute();
    cout << f(0, 0, 0) * fact(n) % MOD;
    return 0;
}