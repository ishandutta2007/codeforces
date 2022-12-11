#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;
int read(void) {
    int x = 0; char c = getchar();
    for (;!isdigit(c);c=getchar());
    for (;isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+(c^48);
    return x;
}
const int N = 1005000;
const int MAXN = 10005000;
const ll inf = 0x7fffffffffff;
inline int Mn(ll x,int y) {return x > y ? y : x;}
inline int Mx(int x,int y) {return x > y ? x : y;}
int gcd(int a, int b) {return !b ? a : gcd(b, a % b);}
int mx, n;
int p[MAXN];
int main() {
    n = read();
    int a1, a2; ll ans = inf;
    for (int i = 1;i <= n; i++) {
        int x = read(); mx = Mx(mx, x);
        if (p[x] && x < ans) a1 = p[x], a2 = i, ans = Mn(ans, x); p[x] = i;
    }
    for (int i = 1;i <= mx; i++) {
        int p1 = 0, p2 = 0;
        for (int j = i;j <= mx; j += i) {
            if (p[j]) {
                if (p1) {p2 = j; break;}
                else p1 = j;
            }
        }
        if (!p2) continue;
        ll tmp = (ll)p1 / gcd(p1, p2) * p2;
        if (ans > tmp) 
            a1 = p[p1], a2 = p[p2], ans = tmp;
    }
    if (a1 > a2) swap(a1, a2);
    cout << a1 << ' ' << a2 << endl;
    return 0;
}