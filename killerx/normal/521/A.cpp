#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read() {
    int x = 0, f = 1, c = getchar();
    for (;!isdigit(c);c = getchar()) if (c == '-') f ^= 1;
    for (; isdigit(c);c = getchar()) x = x * 10 + c - '0';
    return f ? x : -x;
}
char s[100005];
int mod = 1000000007;
int main() {
    int n = read();
    int cnt[4]; memset(cnt, 0, sizeof(cnt));
    scanf("%s", s);
    for (int i = 0; i < n; ++ i) {
        if (s[i] == 'A') ++ cnt[0];
        if (s[i] == 'T') ++ cnt[1];
        if (s[i] == 'G') ++ cnt[2];
        if (s[i] == 'C') ++ cnt[3];
    }
    int mx = max(max(cnt[0], cnt[1]), max(cnt[2], cnt[3]));
    int mxc = 0;
    for (int i = 0; i < 4; ++ i) if (cnt[i] == mx) ++ mxc;
    int ans = 1;
    for (int i = 0; i < n; ++ i) ans = 1LL * ans * mxc % mod;
    printf("%d\n", ans);
    return 0;
}