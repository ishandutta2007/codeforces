#include<bits/stdc++.h>

using namespace std;

const int MAXN = 8005;

int n;
string s;
int p[MAXN], dp[MAXN], len[MAXN];

void precompute () {
    for (int i=1; i<=n; i++) {
        int val = i, br = 0;
        while (val > 0) {
            val /= 10;
            br++;
        }
        len[i] = br;
    }
}

void calc (int ind) {
    dp[ind] = 2 + dp[ind + 1];
    p[ind] = 0;
    int curr = 0;
    for (int i = ind + 1; i < n; i++) {
        while (curr > 0 && s[ind + curr] != s[i]) curr = p[ind + curr - 1];
        if (s[ind + curr] == s[i]) curr++;
        p[i] = curr;
        int siz = i - ind + 1;
        int r = siz - p[i];
        if (siz % r == 0) {
            dp[ind] = min(dp[ind], dp[i + 1] + r + len[siz / r]);
        } else {
            dp[ind] = min(dp[ind], dp[i + 1] + siz + 1);
        }
    }
}

int main () {
    cin >> s;
    n = s.size();
    precompute();
    for (int i = n-1; i >= 0; i--) {
        calc(i);
    }
    cout << dp[0];
    return 0;
}