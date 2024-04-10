#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100005;

typedef long long ll;

struct Seg {
    ll l, r;
    Seg() {}
    Seg(ll l, ll r){
        this->l = l;
        this->r = r;
    }
} b[N], w[N], nb[N];

int h, q;
int bn, wn, nbn;

bool cmp(Seg a, Seg b) {
    return a.l < b.l;
}

bool cmpr(Seg a, Seg b) {
    return a.r < b.r;
}

ll gao() {
    sort(b, b + bn, cmpr);
    ll pre = b[0].r;
    ll bl = (1LL<<(h - 1));
    ll br = (1LL<<h) - 1;
    for (int i = 0; i < bn; i++) {
        if (b[i].l > b[0].r) return -1;
        bl = max(bl, b[i].l);
        br = min(br, b[i].r);
    }
    if (wn == 0) {
        if(br == bl) return br;
    }
    sort(w, w + wn, cmp);
    pre = w[0].r;
    ll prel = w[0].l;
    for (int i = 1; i < wn; i++) {
        if (w[i].l - 1 > pre) {
            nb[nbn++] = Seg(prel, pre);
            prel = w[i].l;
            pre = w[i].r;
        }
        pre = max(pre, w[i].r);
    }
    nb[nbn++] = Seg(prel, pre);
    if (nb[0].l == (1LL<<(h - 1)) && nb[0].r == (1LL<<h) - 1) return -1;
    ll cnt = 0;
    ll v;
    ll sb = max(0LL, min(br, nb[0].l - 1) - bl + 1);
    cnt += sb;
    if (sb == 1) v = bl;
    for (int i = 1; i < nbn; i++) {
        ll sb = max(0LL, min(br, nb[i].l - 1) - max(bl, nb[i - 1].r + 1) + 1);
        cnt += sb;
        if (sb == 1) v = min(br, nb[i].l - 1);
    }
    sb = max(0LL, br - max(bl, nb[nbn - 1].r + 1) + 1);
    cnt += sb;
    if (sb == 1) v = br;
    if (cnt == 1) return v;
    if (cnt == 0) return -1;
    return -2;
}

int main() {
    scanf("%d%d", &h, &q);
    int i;
    ll l, r;
    int tp;
    while (q--) {
        scanf("%d%lld%lld%d", &i, &l, &r, &tp);
        while (i != h) {
            l *= 2;
            r *= 2;
            r++;
            i++;
        }
        if (tp) b[bn++] = Seg(l, r);
        else w[wn++] = Seg(l, r);
    }
    ll tmp = gao();
    if (tmp == -1) printf("Game cheated!\n");
    else if (tmp == -2) printf("Data not sufficient!");
    else printf("%lld\n", tmp);
    return 0;
}