#include <bits/stdc++.h>
using namespace std;

#define B 44
typedef long long ll;

int perf[B];
int sub[B];

bool possible(int i, int o) {
    for (int b = 0; b < B; b++) {
        if (o < sub[b]) return false;
        o -= sub[b];
        if (perf[b] < i) {
            i = perf[b];
            o = min(o, i);
        } else {
            int ex = perf[b] - i;
            if (o < ex) return false;
            o -= ex;
        }
    }
    return true;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        ll v;
        scanf("%lld", &v);
        int w = 0;
        while (1LL << w < v) w++;
        ((v & -v) == v ? perf : sub)[w]++;
    }

    bool found = false;
    for (int i = 1; i <= perf[0]; i++) {
        if (possible(i, i)) {
            if (!found) {
                found = true;
            } else {
                printf(" ");
            }
            printf("%d", i);
        }
    }
    if (!found) {
        printf("-1");
    }
    printf("\n");
}