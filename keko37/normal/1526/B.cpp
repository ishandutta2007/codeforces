#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 100005;

int t, n;
int dp[MAXN];

void precompute () {
    vector <int> v = {11, 111, 1111};
    dp[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        bool ok = 0;
        for (auto x : v) {
            if (i - x >= 0 && dp[i - x] == 1) ok = 1;
        }
        dp[i] = ok;
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    precompute();
    cin >> t;
    while (t--) {
        cin >> n;
        if (n >= MAXN || dp[n]) cout << "YES\n"; else cout << "NO\n";
    }
    return 0;
}