#include <cstdio>
#include <algorithm>
#include <numeric>
#include <iterator>
using namespace std;

int s[100000];
int m[100000];
int rg[100000];
bool good[(1 << 18) - 1];
int last[(1 << 18) - 1];
int tmax[18][1 << 17];
int tmp[18][1 << 17];
long long summax[18][1 << 17];
long long sumreg[18][1 << 17];

int mydiv(int i, int j) {
    return j ? (i + j - 1) / j : 1234567890;
}

void build(int l = 0, int r = 1 << 17, int d = 0) {
    if(l + 1 == r) {
        tmp[d][l] = l;
        tmax[d][l] = mydiv(m[l], rg[l]);
        summax[d][l] = m[l];
        sumreg[d][l] = rg[l];
    } else {
        build(l, (l + r) / 2, d + 1);
        build((l + r) / 2, r, d + 1);
        merge(tmp[d + 1] + l, tmp[d + 1] + (l + r) / 2,
              tmp[d + 1] + (l + r) / 2, tmp[d + 1] + r,
              tmp[d] + l, [](int i, int j){
            return mydiv(m[i], rg[i]) < mydiv(m[j], rg[j]);
        });
        for(int i = l; i < r; i++) {
              tmax[d][i] = mydiv(m[tmp[d][i]], rg[tmp[d][i]]);
            summax[d][i] = m[tmp[d][i]];
            sumreg[d][i] = rg[tmp[d][i]];
        }
        partial_sum(summax[d] + l, summax[d] + r, summax[d] + l);
        partial_sum(reverse_iterator<long long*>(sumreg[d] + r),
                    reverse_iterator<long long*>(sumreg[d] + l),
                    reverse_iterator<long long*>(sumreg[d] + r));
    }
}

long long query(int t, int l, int r, int nl = 0, int nr = 1 << 17, int k = 0, int d = 0) {
    if(l <= nl && nr <= r && good[k]) {
        int p = upper_bound(tmax[d] + nl, tmax[d] + nr, t - last[k]) - tmax[d];
        long long a = p == nl ? 0 : summax[d][p - 1];
        long long b = p == nr ? 0 : sumreg[d][p] * (t - last[k]);
        last[k] = t;
//        fprintf(stderr, "^ %d %d %d\n", nl, nr, (int) (a + b));
        return a + b;
    } else if(!(r <= nl || nr <= l)){
        if(nl + 1 == nr) {
            long long a = min((long long) m[nl], s[nl] + (long long) rg[nl] * (t - last[k]));
            s[nl] = 0;
            good[k] = true;
            last[k] = t;
//            fprintf(stderr, "> %d\n", (int) a);
            return a;
        }
        if(good[k]) {
            good[k] = false;
            good[2 * k + 1] = true;
            last[2 * k + 1] = last[k];
            good[2 * k + 2] = true;
            last[2 * k + 2] = last[k];
        }
        long long a = query(t, l, r, nl, (nl + nr) / 2, 2 * k + 1, d + 1);
        long long b = query(t, l, r, (nl + nr) / 2, nr, 2 * k + 2, d + 1);
        good[k] = l <= nl && nr <= r;
        last[k] = t;
        return a + b;
    } else {
        return 0;
    }
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d %d %d", s + i, m + i, rg + i);
    build();
    int q;
    scanf("%d", &q);
    while(q--) {
        int t, l, r;
        scanf("%d %d %d", &t, &l, &r);
        l--;
#pragma GCC diagnostic ignored "-Wformat"
        printf("%I64d\n", query(t, l, r));
#pragma GCC diagnostic pop
    }
}