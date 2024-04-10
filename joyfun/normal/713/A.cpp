#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 100005;
int q;

int ch[N * 30][2], val[N * 30], sz;

char str[N];

int bit[N], bn;

void get(long long x) {
    bn = 0;
    while (x) {
        int yu = x % 10;
        bit[++bn] = yu % 2;
        x /= 10;
    }
    while (bn <= 20) bit[++bn] = 0;
}

void ins(int f) {
    int u = 0;
    for (int i = 1; i <= bn; i++) {
        int c = bit[i];
        if (!ch[u][c]) {
            ch[u][c] = ++sz;
        }
        u = ch[u][c];
    }
     val[u] += f;
}

int qy(char *str) {
    int len = strlen(str);
    reverse(str, str +len);
    while (len <= 20) str[len++] = '0';
    int u = 0;
    int ans = 0;
    for (int i = 0; i < len; i++) {
        int c = str[i] - '0';
        if (!ch[u][c]) return 0;
        u = ch[u][c];
    }
    return val[u];
}

int main() {
    scanf("%d", &q);
    char op[10];
    long long x;
    while (q--) {
        scanf("%s", op);
        if (op[0] == '?') {
            scanf("%s", str);
            printf("%d\n", qy(str));
        } else {
            scanf("%lld", &x);
            get(x);
            ins(op[0] == '+' ? 1 : -1);
        }
    }
    return 0;
}