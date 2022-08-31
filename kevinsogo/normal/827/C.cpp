#include <bits/stdc++.h>
using namespace std;

struct Fen {
    int n;
    int *a;
    Fen(int n): n(n) {
        a = new int[n+1];
        for (int i = 0; i <= n; i++) a[i] = 0;
    }
    void inc(int i, int v) {
        for (i++; i <= n; i += i & -i) {
            a[i] += v;
        }
    }
    int sum(int i) {
        int s = 0;
        for (; i; i -= i & -i) {
            s += a[i];
        }
        return s;
    }
};

#define N 111111
#define D 11
char s[N + 1];
char v[D + 1];
int n;
// int *val[D][D][26];
Fen *val[D][D][26];
void init() {
    for (int k = 1; k < D; k++) {
        for (int i = 0; i < k; i++) {
            for (char c = 0; c < 26; c++) {
                // val[k][i][c] = new int[N / k + 2];
                val[k][i][c] = new Fen(N / k + 4);
            }
        }
    }
}
int inc(int i, char c, int d) {
    // val[c][i] += d;
    for (int k = 1; k < D; k++) {
        // val[k][i % k][c][i / k] += d;
        val[k][i % k][c]->inc(i / k, d);
    }
}
int query(int l, int r, int k, char c) {
    int m = l % k;
    return val[k][m][c]->sum((r - m + k - 1) / k) - val[k][m][c]->sum(l / k);
    // int ans = 0;
    // for (int i = l / k; i <= (r - m - 1) / k; i++) {
    //     ans += val[k][m][c][i];
    // }
    // return ans;
}



int main() {
    int q;
    scanf("%s%d", s, &q);
    n = strlen(s);
    init();
    for (int i = 0; i < n; i++) {
        s[i] -= 'A';
        inc(i, s[i], 1);
    }
    while (q--) {
        int typ;
        scanf("%d", &typ);
        if (typ == 1) {
            // update
            int i;
            scanf("%d%s", &i, v);
            *v -= 'A';
            i--;
            inc(i, s[i], -1);
            s[i] = *v;
            inc(i, s[i], 1);
        } else {
            int l, r;
            scanf("%d%d%s", &l, &r, v);
            l--;
            int k = strlen(v);
            int ans = 0;
            for (int i = 0; i < k; i++) {
                v[i] -= 'A';
                ans += query(l + i, r, k, v[i]);
            }
            printf("%d\n", ans);
        }
    }
}