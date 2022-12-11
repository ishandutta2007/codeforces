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
const int N = 2050;
int vis[N], n, T;
int query(vector<int> &A, vector<int> &B) {
    cout << "? " << A.size() << ' ' << B.size() << endl;
    for (int i = 0;i < A.size(); ++i) cout << A[i] << " \n"[i + 1 == A.size()];
    for (int i = 0;i < B.size(); ++i) cout << B[i] << " \n"[i + 1 == B.size()];
    fflush(stdout);
    int ans;
    cin >> ans;
    return ans;
}

void work(int x, int t) {
    vis[x] = 1;
    vector<int> A(1), B(1);
    A[0] = x;
    t = abs(t) & 1;
    for (int i = x + 1;i < n; ++i) {
        B[0] = i;
        if (query(A, B)) vis[i] = 1, t ^= 1;
    }
    vis[n] = t;
    int l = 1, r = x - 1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        B.resize(mid - l + 1);
        for (int i = l;i <= mid; ++i) B[i - l] = i;
        if (query(A, B)) r = mid - 1;
        else l = mid + 1;
    }
    vis[l] = 1;
    int ans = 0;
    for (int i = 1;i <= n; ++i) ans += !vis[i];
    cout << "! " << ans << ' ';
    for (int i = 1;i <= n; ++i)
        if (!vis[i]) cout << i << " \n"[!--ans];
    fflush(stdout);
}

int main() {
    ios::sync_with_stdio(false);
    for (cin >> T; T; T--) {
        memset(vis, 0, sizeof(vis));
        cin >> n;
        vector<int> L(1), R;
        for (int i = 1;i <= n; ++i) R.push_back(n - i + 1);
        for (int i = 1, t;i <= n; ++i) {
            R.pop_back(), L[0] = i;
            if (t = query(L, R)) { work(i, t); break; }
        }
    }
    return 0;
}