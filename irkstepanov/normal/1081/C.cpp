#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int mod = 998244353;

void add(int& a, int b) {
    a += b;
    if (a >= mod) {
        a -= mod;
    }
}

void mul(int& a, int b) {
    ll c = ll(a) * b;
    if (c >= mod) {
        c %= mod;
    }
    a = c;
}

const int nmax = 2018;

int dp[2][nmax];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    k = n - 1 - k;

    dp[0][0] = 1;
    int ptr = 0;
    for (int i = 1; i < n; ++i) {
        memset(dp[ptr ^ 1], 0, sizeof(dp[ptr ^ 1]));
        for (int j = 0; j <= k; ++j) {
            int val = dp[ptr][j];
            mul(val, m - 1);
            if (j - 1 >= 0) {
                add(val, dp[ptr][j - 1]);
            }
            dp[ptr ^ 1][j] = val;
        }
        ptr ^= 1;
    }

    int val = dp[ptr][k];
    mul(val, m);

    cout << val << "\n";
    
}