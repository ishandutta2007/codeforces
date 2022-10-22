#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxn = 2e5 + 5;
const int sigma = 26;

int n;
char s1[mxn], s2[mxn];
int cnt[sigma];

void Main() {
    scanf("%d", &n);
    scanf("%s", s1);
    scanf("%s", s2);
    long long ans = 0;
    rep(c, sigma) cnt[c] = 0;
    for (int i = n - 1; ~i; -- i) {
        rep(c, s1[i] - 'a') ans += cnt[c];
        cnt[s1[i] - 'a'] += 1;
    }
    bool can1 = false;
    rep(c, sigma) can1 |= cnt[c] > 1;
    rep(c, sigma) cnt[c] = 0;
    for (int i = n - 1; ~i; -- i) {
        rep(c, s2[i] - 'a') ans -= cnt[c];
        cnt[s2[i] - 'a'] += 1;
    }
    bool can2 = false;
    rep(c, sigma) can2 |= cnt[c] > 1;
    if (ans % 2 == +1 && !can2) {
        puts("NO");
        return ;
    }
    if (ans % 2 == -1 && !can1) {
        puts("NO");
        return ;
    }
    std::sort(s1, s1 + n);
    std::sort(s2, s2 + n);
    rep(i, n) if (s1[i] != s2[i]) {
        puts("NO");
        return ;
    }
    puts("YES");
}

int main() {
    int T; scanf("%d", &T);
    while (T --) Main();
    return 0;
}