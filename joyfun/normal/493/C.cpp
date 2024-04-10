#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 400005;
int n, m;

struct Man {
    int v, tp;
    Man() {}
    Man(int v, int tp) {
        this->v = v;
        this->tp = tp;
    }
} man[N];
    
int tot;

bool cmp(Man a, Man b) {
    return a.v < b.v;
}

int prea[N], preb[N];

int main() {
    scanf("%d", &n);
    int tmp;
    tot = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &tmp);
        man[++tot] = Man(tmp, 0);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &tmp);
        man[++tot] = Man(tmp, 1);
    }
    sort(man + 1, man + tot + 1, cmp);
    int ansa = n * 3, ansb = m * 3;
    for (int i = 1; i <= tot; i++) {
        prea[i] = prea[i - 1];
        preb[i] = preb[i - 1];
        if (man[i].tp == 0) prea[i]++;
        else preb[i]++;
        if (man[i].v == man[i + 1].v) continue;
        int aa = prea[i] * 2 + (n - prea[i]) * 3;
        int bb = preb[i] * 2 + (m - preb[i]) * 3;
        if (ansa - ansb < aa - bb) {
            ansa = aa;
            ansb = bb;
        } else if (ansa - ansb == aa - bb && ansa < aa) {
            ansa = aa;
            ansb = bb;
        }
    }
    printf("%d:%d\n", ansa, ansb);
    return 0;
}