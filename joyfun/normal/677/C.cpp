#include <cstdio>
#include <cstring>

const int N = 100005;
char str[N];

int get(char x) {
    if (x >= '0' && x <= '9') return x - '0';
    else if (x >= 'A' && x <= 'Z') return 10 + x - 'A';
    else if (x >= 'a' && x <= 'z') return 36 + x - 'a';
    else if (x == '-') return 62;
    return 63;
}

int bit[64];

int bic(int x){
    if (!x) return 0;
    return bic(x / 2) + x % 2;
}

const int MOD = 1000000007;
int p3[10];

int main() {
    p3[0] = 1;
    for (int i = 1; i < 10; i++) p3[i] = 1LL * p3[i - 1] * 3 % MOD;
    for (int i = 0; i < 64; i++) bit[i] = bic(i);
    scanf("%s", str);
    int n = strlen(str);
    int ans = 1;
    for (int i = 0; i < n; i++) {
        ans = (1LL * ans * p3[6 - bit[get(str[i])]] % MOD);
    }
    printf("%d\n", ans);
    return 0;
}