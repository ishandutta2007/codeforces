#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

typedef std::bitset <2048> bs;

int n;
int a[10005];

bool check(int len) {
    static bs ini;
    rep(i, 2048) ini[i] = i < len;
    static bs b;
    b = ini;
    for (int i = n - 1; ~i; -- i) {
        b = (b << a[i]) | (b >> a[i]);
        b &= ini;
    }
    rep(i, len) if (b[i]) return true;
    return false;
}

void Main() {
    scanf("%d", &n);
    rep(i, n) scanf("%d", &a[i]);
    int lb = 1, rb = 2000;
    while (lb < rb) {
        int md = (lb + rb) >> 1;
        if (check(md)) rb = md;
        else lb = md + 1;
    }
    printf("%d\n", lb - 1);
}

int main() {
    int T; scanf("%d", &T);
    while (T --) Main();
    return 0;
}