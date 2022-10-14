#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <llint, llint> pi;

const int MAXN = 1000005;

int n, k, len, sol = MAXN, cost;
string s;
int a[MAXN];
pi dp[MAXN];

pi add (pi a, pi b) {return {a.first + b.first, a.second + b.second};}

pi f () {
    for (int i = 0; i < n; i++) {
        if (i == 0) dp[i] = {a[i], 0}; else dp[i] = add(dp[i-1], {a[i], 0});
        if (i - len < 0) {
            dp[i] = min(dp[i], {cost, -1});
        } else {
            dp[i] = min(dp[i], add(dp[i - len], {cost, -1}));
        }
    }
    dp[n-1].second *= -1;
    return dp[n-1];
}

int calc () {
    llint lo = 0, hi = 1e9;
    while (lo < hi) {
        cost = (lo + hi + 1) / 2;
        if (f().second >= k) {
            lo = cost;
        } else {
            hi = cost - 1;
        }
    }
    cost = lo;
    return f().first - lo * k;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k >> len >> s;
    for (int i = 0; i < n; i++) a[i] = ('a' <= s[i] && s[i] <= 'z');
    sol = min(sol, calc());
    for (int i = 0; i < n; i++) a[i] = ('A' <= s[i] && s[i] <= 'Z');
    sol = min(sol, calc());
    cout << sol;
    return 0;
}