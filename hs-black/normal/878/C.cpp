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

#include <set>
const int K = 11;
const int N = 50050;
set<pair<int, int> > st;
int f[N], L[N][K], R[N][K], siz[N], n, k;
inline bool cs(int x, int y) {
    for (int i = 1;i <= k; ++i) {
        if (min(R[x][i], R[y][i]) >= max(L[x][i], L[y][i])) return 1;
        if ((L[x][i] > L[y][i]) != (L[x][1] > L[y][1])) return 1;
    }
    return 0;
}
inline void merge(int x, int y) {
    siz[x] += siz[y], st.erase(MP(L[y][1], y));
    for (int i = 1;i <= k; ++i) 
        L[x][i] = min(L[x][i], L[y][i]),
        R[x][i] = max(R[x][i], R[y][i]);
}
int main() {
    read(n), read(k);
    for (int i = 1;i <= n; ++i) siz[i] = 1;
    for (int i = 1;i <= n; ++i) {
        for (int j = 1;j <= k; ++j) read(L[i][j]);
        memcpy(R[i], L[i], sizeof(L[i]));
        while (st.size()) {
            auto t = st.lower_bound(MP(L[i][1], 0));
            if (t == st.end()) break;
            if (cs(i, t->se)) merge(i, t->se);
            else break;
        } 
        while (st.size()) {
            auto t = st.lower_bound(MP(L[i][1], 0));
            if (t == st.begin()) break;
            --t;
            if (cs(i, t->se)) merge(i, t->se);
            else break;
        }
        st.insert(MP(L[i][1], i));
        write(siz[(--st.end())->se]);
    }
    return 0;
}