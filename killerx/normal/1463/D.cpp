#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

int n;
bool hav[400005];

void Main() {
    scanf("%d", &n);
    memset(hav, 0, n << 1);
    rep(i, n) {
        int b;
        scanf("%d", &b);
        -- b;
        hav[b] = 1;
    }
    int sum = 0, mn = 0;
    int ans = n + 1;
    rep(i, n << 1) {
        sum += hav[i] ? +1 : -1;
        mn = min(mn, sum);
    }
    ans += mn;
    sum = 0, mn = 0;
    for (int i = (n << 1) - 1; ~i; -- i) {
        sum += hav[i] ? +1 : -1;
        mn = min(mn, sum);
    }
    ans += mn;
    printf("%d\n", max(0, ans));
}

int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        Main();
    }
    return 0;
}