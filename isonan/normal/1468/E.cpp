#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') { fu = -1; } c = getchar(); }
    while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

int a[4];
int T, ans;

int main() {
    read(T);
    while (T--) {
        ans = 0;
        for (int i = 0; i < 4; i++) read(a[i]);
        for (int i = 0; i < 4; i++) {
            for (int j = i + 1; j < 4; j++) {
                int len1 = min(a[i], a[j]), len2 = 1e9;
                for (int k = 0; k < 4; k++) {
                    if (i != k && j != k) len2 = min(len2, a[k]);
                }
                ans = max(ans, len1 * len2);
            }
        }
        print(ans, '\n');
    }
    return 0;
}