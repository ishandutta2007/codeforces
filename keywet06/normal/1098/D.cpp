#include <bits/stdc++.h>

using int64 = long long;

int64 s[30];

std::multiset<int> x;

void ins(int pl, int num) {
    for (int i = 0; i < 30; ++i) {
        if (pl <= (1 << i)) s[i] += num;
    }
}

int main() {
    int qs;
    scanf("%d", &qs);
    int sz = 0;
    for (int i = 0; i < qs; ++i) {
        char inp[3];
        int num;
        scanf("%s", inp);
        scanf("%d", &num);
        int pl = 0;
        if (inp[0] == '+') {
            pl = 1, x.insert(num);
        } else {
            pl = -1, x.erase(x.find(num));
        }
        ins(num, num * pl);
        sz += pl;
        int ans = sz - 1;
        if (sz == 0) ans = 0;
        int lst = 0;
        for (int i = 0; i < 30; ++i) {
            int64 n1 = s[i];
            if (!n1) continue;
            if (lst > (1 << i)) continue;
            int m1 = *x.upper_bound(1 << i);
            if (n1 * 2 < m1 && m1 != lst) lst = m1, --ans;
        }
        printf("%d\n", ans);
    }
    return 0;
}