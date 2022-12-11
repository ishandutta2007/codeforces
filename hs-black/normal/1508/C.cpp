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

#include <vector>
#include <map>
map<pair<int, int>, int> mp;
const int N = 400050;
const int inf = 2e9;
int f[N], col[N], m, n;
ll v[N]; ll ans; int answ;
inline int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
struct edges {
    int x, y, z;
    bool operator < (const edges &i) const {
        return z < i.z;
    }
    void init(void) {
        read(x), read(y), read(z), answ ^= z;
        if (x > y) swap(x, y);
        mp[MP(x, y)] = 1;
    }
}ed[N];

vector<int> vec[N]; int tp;
int main() {
    read(n), read(m);
    for (int i = 1;i <= m; ++i) ed[i].init();
    for (int i = 1;i <= n; ++i) {
        vector<int> tmp; tmp.push_back(i);
        int tt = 0;
        for (int j = 1;j <= tp; ++j) {
            int fl = 0;
            for (auto t: vec[j]) {
                /* if (i == 4) printf ("4 -> %d\n", t); */
                if (!mp.count(MP(t, i))) {
                    if (tmp.size() < vec[j].size()) tmp.swap(vec[j]);
                    for (auto k: vec[j]) tmp.push_back(k);
                    fl = 1; break;
                }
            }
            if (!fl) {
                ++tt; vec[tt].swap(vec[j]);   
            }
        }
        /* for (auto t: tmp) write(t, ' '); */
        tp = tt + 1, vec[tp].swap(tmp);
        /* puts(""); write(tp); OK; OK; */
    }
    /* write(mp.count(MP(2, 4))); */
    sort(ed + 1, ed + m + 1);
    for (int i = 1;i <= tp; ++i) {
        ll tsz = vec[i].size();
        f[i + n] = i + n, v[i] = tsz * (tsz - 1) / 2;
        /* printf ("col[%d] contains: \n", i); */
        for (auto t: vec[i]) f[t] = i + n, col[t] = i;
        /* puts(""); */
    }
    for (int i = 1, x, y;i <= m; ++i) {
        x = ed[i].x, y = ed[i].y;
        if (col[x] == col[y]) { --v[col[x]]; continue; }
        x = find(x), y = find(y); if (x == y) continue;
        f[x] = y, ans += ed[i].z, ed[i].z = inf;
    }
    for (int i = 1;i <= n; ++i) f[i] = i;
    for (int i = 1;i <= m; ++i) if (ed[i].z == inf) {
        int x = find(ed[i].x), y = find(ed[i].y);
        f[x] = y;
    }
    for (int i = 1;i <= tp; ++i)
        if (vec[i].size() > 1 && v[i] >= vec[i].size()) answ = 0;
    for (int i = 1;i <= m; ++i) if (find(ed[i].x) != find(ed[i].y)) answ = min(answ, ed[i].z);
    write(answ + ans);
    return 0;
}