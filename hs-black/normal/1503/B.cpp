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
int n;
vector<pair<int, int> > st[2];
void out(vector<pair<int, int> > &res, int c) {
    pair<int, int> tp = res.back(); res.pop_back();
    cout << c << ' ' << tp.fi << ' ' << tp.se << endl;
    fflush(stdout);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1;i <= n; ++i)
        for (int j = 1;j <= n; ++j)
            st[(i + j) & 1].push_back(MP(i, j));
    for (int i = 1;i <= n * n; ++i) {
        int x;
        cin >> x; 
        if (x == 1) {
            if (st[1].size()) {
                out(st[1], 2);
            } else {
                out(st[0], 3);
            }
        } else if (x == 2) {
            if (st[0].size()) out(st[0], 1);
            else out(st[1], 3);
        } else {
            if (st[1].size()) out(st[1], 2);
            else if (st[0].size()) out(st[0], 1);
        }
    }
    return 0;
}