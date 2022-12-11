/*
   
  | _ _|
   ` _x 
    /  |
   /   ?
  | |||
  | (__)_)
  
 
 */

#define OK printf ("Pass on Line #%d\n", __LINE__)
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MP make_pair
#define ll long long
#define fi first
#define se second
using namespace std;

template <typename T>
void read(T &x) {
    x = 0; bool f = 0;
    char c = getchar();
    for (;!isdigit(c);c=getchar()) if (c=='-') f=1;
    for (;isdigit(c);c=getchar()) x=x*10+(c^48);
    if (f) x=-x;
}

template<typename F>
inline void write(F x, char ed = '\n') {
    static short st[30];short tp=0;
    if(x<0) putchar('-'),x=-x;
    do st[++tp]=x%10,x/=10; while(x);
    while(tp) putchar('0'|st[tp--]);
    putchar(ed);
}

template <typename T>
inline void write(T *st, int n, string s = "") {
    if (s.size()) cout << s << ": ";
    while (n--) write(*st++, ' ');
    puts("");
}

const int N = 400500;
struct node { int mn, mx; }v[N<<2], tag[N<<2];
#define ls p << 1
#define rs ls | 1
void build(int p, int l, int r) {
    tag[p] = v[p] = (node){(int)1e9, 0};
    if (l == r) return;
    int mid = (l + r) >> 1;
    build(ls, l, mid), build(rs, mid + 1, r);
}

void Tag(int p, node t) {
    tag[p].mx = max(tag[p].mx, t.mx), tag[p].mn = min(tag[p].mn, t.mn);
    v[p].mx = max(v[p].mx, t.mx), v[p].mn = min(v[p].mn, t.mn);
}

void spread(int p) { Tag(ls, tag[p]), Tag(rs, tag[p]); }
void change(int p, int l, int r, int L, int R, node t) {
    if (L <= l && r <= R) return Tag(p, t);
    int mid = (l + r) >> 1; spread(p);
    if (L <= mid) change(ls, l, mid, L, R, t);
    if (R > mid) change(rs, mid + 1, r, L, R, t);
    v[p].mn = min(v[ls].mn, v[rs].mn);
    v[p].mx = max(v[ls].mx, v[rs].mx);
}

node query(int p, int l, int r, int L, int R) {
    if (L <= l && r <= R) return v[p];
    int mid = (l + r) >> 1; spread(p);
    if (L > mid) return query(rs, mid + 1, r, L, R);
    if (R <= mid) return query(ls, l, mid, L, R);
    node r1 = query(ls, l, mid, L, R), r2 = query(rs, mid + 1, r, L, R);
    return (node){min(r1.mn, r2.mn), max(r1.mx, r2.mx)};
}

int n, sa[N], sb[N], ea[N], eb[N], c[N], cnt;
int main() {
    read(n);
    for (int i = 1;i <= n; ++i) {
        read(sa[i]), read(ea[i]), read(sb[i]), read(eb[i]);
        c[++cnt] = sa[i], c[++cnt] = ea[i];
    }
    sort(c + 1, c + cnt + 1), cnt = unique(c + 1, c + cnt + 1) - c - 1;
    build(1, 1, cnt);
    for (int i = 1;i <= n; ++i) {
        sa[i] = lower_bound(c + 1, c + cnt + 1, sa[i]) - c;
        ea[i] = lower_bound(c + 1, c + cnt + 1, ea[i]) - c;
        change(1, 1, cnt, sa[i], ea[i], (node){eb[i], sb[i]});
        node t = query(1, 1, cnt, sa[i], ea[i]);
        /* write(t.mx, ' '), write(t.mn); */
        if (t.mx > eb[i] || t.mn < sb[i]) return puts("NO"), 0;
    }
    cnt = 0;
    for (int i = 1;i <= n; ++i) {
        swap(sa[i], sb[i]), swap(ea[i], eb[i]);
        c[++cnt] = sa[i], c[++cnt] = ea[i];
    }
    sort(c + 1, c + cnt + 1), cnt = unique(c + 1, c + cnt + 1) - c - 1;
    build(1, 1, cnt);
    for (int i = 1;i <= n; ++i) {
        sa[i] = lower_bound(c + 1, c + cnt + 1, sa[i]) - c;
        ea[i] = lower_bound(c + 1, c + cnt + 1, ea[i]) - c;
        change(1, 1, cnt, sa[i], ea[i], (node){eb[i], sb[i]});
        node t = query(1, 1, cnt, sa[i], ea[i]);
        if (t.mx > eb[i] || t.mn < sb[i]) return puts("NO"), 0;
    }
    puts("YES");
    return 0;
}