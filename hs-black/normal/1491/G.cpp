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
const int N = 200500;
int p[N], vis[N], n, tp;
int x[N], y[N], cnt;
inline void F(int x, int y) { ::x[++tp] = x, ::y[tp] = y; }
vector<int> vec[N];
void solve(void) {
    int sp = 0;
    for (int i = 1, x;i <= n; ++i) if (!vis[i]) {
        vis[x = i] = 1, x = p[x];
        if (p[i] == i) { sp = i; continue; }
        vec[++cnt].push_back(i);
        while (x != i) vec[cnt].push_back(x), vis[x] = 1, x = p[x];
    }
    for (int i = 1;i + 1 <= cnt; i += 2) {
        F(vec[i].back(), vec[i + 1].back());
        for (int j = 0;j + 1 < vec[i + 1].size(); ++j)
            F(vec[i].back(), vec[i + 1][j]);
        for (int j = 0;j < vec[i].size(); ++j)
            F(vec[i + 1].back(), vec[i][j]);
        sp = vec[i][0];
    }
    if (~cnt & 1) return;
    if (vec[cnt].size() == 2) return F(vec[cnt][0], sp), F(vec[cnt][1], sp), F(vec[cnt][0], sp);
    int t = vec[cnt][0], tt = vec[cnt].back(), ttt = vec[cnt][vec[cnt].size() - 2];
    F(t, tt);
    for (int i = 1;i + 2 < vec[cnt].size(); ++i) F(tt, vec[cnt][i]);
    F(ttt, t), F(tt, ttt), F(tt, t);
}

int main() {
    read(n);
    for (int i = 1;i <= n; ++i) read(p[i]);
    solve(), write(tp);
    for (int i = 1;i <= tp; ++i) write(x[i], ' '), write(y[i]);
    return 0;
}