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

char s[22];
bool ask(ll x) {  cout << "? " << x << endl; fflush(stdout); cin >> s; return s[0] == 'L'; }
void out(ll x) { cout << "! " << x << endl; fflush(stdout); }
ll V, C = 0;
/* bool ask(ll x) { ++C; return V >= x; } */
/* void out(ll x) { cout << "! " << x << "with the times: " << C << endl; fflush(stdout); } */
ll mny;
void step(ll pre, ll nw) {
    while (mny < nw) 
        ask(pre), mny += pre;
}
void solve() {
    /* read(V), C = 0; */
    ll L = 1, R = 1e14; mny = 1;
    for (int i = 0;(1ll << i) <= R; ++i) {
        int t = ask(1ll << i);
        if (!t) {
            R = (1ll << i) - 1;
            if (i == 0) return out(0);
            mny -= 1ll << i;
            break;
        }
        mny += 1ll << i;
        L = 1ll << i;
    }
    while (L < R) {
        double sb = 0.5 * mny / (mny + R); 
        ll mid = (R - L - 1) * sb + L + 1;
        if (mid < L) mid = L + 1;
        step(L, mid);
        int t = ask(mid);
        if (t) L = mid, mny += mid;
        else R = mid - 1, mny -= mid;
    }
    out(L);
}

int T;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    for (cin >> T; T; T--) solve();
    return 0;
}