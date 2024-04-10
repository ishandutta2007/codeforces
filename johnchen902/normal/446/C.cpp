#include <cstdio>
#include <numeric>
using namespace std;

constexpr int module = 1000000009;

int fibo[300001];
int fibosum[300001];

int get_fibo(int a, int b, int k) {
    if(k == 0) return a;
    // if(k == 1) return b;
    int ans = ((long long) a * fibo[k] + (long long) (b - a) * fibo[k - 1]) % module;
    if(ans < 0) ans += module;
    return ans;
}

int get_fibosum(int a, int b, int k) {
    if(k == 0) return 0;
    if(k == 1) return a;
    // if(k == 2) return (a + b) % module;
    int ans = ((long long) a * fibosum[k - 1] + (long long) (b - a) * fibosum[k - 2]) % module;
    if(ans < 0) ans += module;
    return ans;
}

struct Node {
    int sum;
    int first, second;
} seg[(1 << 20) - 1];

void pull(int nl, int nr, int k) {
    if(nl + 1 < nr)
        seg[k].sum = (seg[2 * k + 1].sum + seg[2 * k + 2].sum) % module;
    else
        seg[k].sum = 0;
    seg[k].sum = (seg[k].sum + get_fibosum(seg[k].first, seg[k].second, nr - nl)) % module;
}

void insert(int l, int r, int first, int second, int nl, int nr, int k);

void push(int nl, int nr, int k) {
    if(seg[k].first || seg[k].second) {
        insert(nl, nr, seg[k].first, seg[k].second, nl, (nl + nr) / 2, 2 * k + 1);
        insert(nl, nr, seg[k].first, seg[k].second, (nl + nr) / 2, nr, 2 * k + 2);
        seg[k].first = seg[k].second = 0;
    }
}

void build(int n, int nl = 0, int nr = 1 << 19, int k = 0) {
    if(nl + 1 == nr) {
        if(nl < n)
            scanf("%d", &seg[k].first);
        seg[k].sum = seg[k].first;
    } else {
        build(n, nl, (nl + nr) / 2, 2 * k + 1);
        build(n, (nl + nr) / 2, nr, 2 * k + 2);
        pull(nl, nr, k);
    }
}

void insert(int l, int r, int first = 1, int second = 1, int nl = 0, int nr = 1 << 19, int k = 0) {
    if(l <= nl && nr <= r) {
        seg[k].first  = (seg[k].first  + get_fibo(first, second, nl - l    )) % module;
        seg[k].second = (seg[k].second + get_fibo(first, second, nl - l + 1)) % module;
        pull(nl, nr, k);
    } else if(!(r <= nl || nr <= l)) {
        insert(l, r, first, second, nl, (nl + nr) / 2, 2 * k + 1);
        insert(l, r, first, second, (nl + nr) / 2, nr, 2 * k + 2);
        pull(nl, nr, k);
    }
}

int query(int l, int r, int nl = 0, int nr = 1 << 19, int k = 0) {
    if(l <= nl && nr <= r) {
        return seg[k].sum;
    } else if(!(r <= nl || nr <= l)) {
        push(nl, nr, k);
        return (query(l, r, nl, (nl + nr) / 2, 2 * k + 1) +
                query(l, r, (nl + nr) / 2, nr, 2 * k + 2)) % module;
    } else {
        return 0;
    }
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    fibo[0] = fibo[1] = 1;
    fibosum[0] = 1; fibosum[1] = 2;
    for(int i = 2; i <= n; i++) {
        fibo[i] = (fibo[i - 1] + fibo[i - 2]) % module;
        fibosum[i] = (fibosum[i - 1] + fibo[i]) % module;
    }
    build(n);
    while(m--) {
        int q, l, r;
        scanf("%d %d %d", &q, &l, &r);
        l--;
        if(q == 1) {
            insert(l, r);
        } else {
            printf("%d\n", query(l, r));
        }
    }
}