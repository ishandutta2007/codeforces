#include<bits/stdc++.h>
#define reg register
#define ll long long
using namespace std;
inline int read() {
    int x=0,f=1,c=getchar();
    for (;c< 48;c=getchar()) if (c=='-') f=0;
    for (;c>=48;c=getchar()) x = x*10 + c-'0';
    return f?x:-x;
}
char s[1<<20];
int main() {
    int n, k; n = read(), k = read();
    scanf("%s", s); int m = strlen(s);
    vector <int> lst(k, -1);
    int mod = 1e9 + 7;
    vector <ll> dp(m + n + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < m; ++ i) {
        (dp[i + 1] += 2 * dp[i]) %= mod;
        if (~lst[s[i] - 'a']) (dp[i + 1] += mod - dp[lst[s[i] - 'a']]) %= mod;
        lst[s[i] - 'a'] = i;
    }
    for (int i = m; i < m + n; ++ i) {
        (dp[i + 1] += 2 * dp[i]) %= mod;
        char mn = 'a';
        for (int c = 'a'; c < 'a' + k; ++ c) if (lst[c - 'a'] < lst[mn - 'a']) mn = c;
        if (~lst[mn - 'a']) (dp[i + 1] += mod - dp[lst[mn - 'a']]) %= mod;
        lst[mn - 'a'] = i;
    }
    cout << dp[m + n] << endl;
    return 0;
}