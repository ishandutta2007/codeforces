#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 200005;

struct Str {
    char c;
    long long l;
    Str() {}
    Str(char c, long long l) : c(c), l(l) {}
    bool operator == (const Str& x) const {
        return c == x.c && l == x.l;
    }
    bool operator != (const Str &x) const {
        return !(*this == x);
    }
} a[N], b[N];
int n, m, an, bn;

void read(Str *a, int &an, int n) {
    an = 0;
    long long l; char c;
    for (int i = 1; i <= n; i++) {
        scanf("%lld-%c", &l, &c);
        if (an && c == a[an].c) a[an].l += l;
        else a[++an] = Str(c, l);
    }
}

int jump[N];

bool cao(Str a, Str b) {
    return a.c == b.c && a.l <= b.l;
}

long long solve() {
    if (bn == 1) {
        long long ans = 0;
        for (int i = 1; i <= an; i++) {
            if (a[i].c == b[1].c) {
                ans += max(0LL, a[i].l - b[1].l + 1);
            }
        }
        return ans;
    }
    Str head = b[1], rear = b[bn];
    for (int i = 1; i < bn; i++) b[i] = b[i + 1]; bn -= 2;
    jump[1] = 0; int j = 0;
    for (int i = 2; i <= bn; i++) {
        while (j && b[i] != b[j + 1]) j = jump[j];
        if (b[i] == b[j + 1]) j++;
        jump[i] = j;
    }
    long long ans = 0; j = 0;
    for (int i = 1; i <= an; i++) {
        while (j && a[i] != b[j + 1]) j = jump[j];
        if (a[i] == b[j + 1]) j++;
        if (j == bn) {
            if (i > bn && i < an) {
                if (cao(head, a[i - bn]) && cao(rear, a[i + 1])) ans++;
            }
            j = jump[j];
        }
    }
    return ans;
}

int main() {
    scanf("%d%d", &n, &m);
    read(a, an, n);
    read(b, bn, m);
    printf("%lld\n", solve());
    return 0;
}