// Hydro submission #62596d9537de167dd82c25fa@1650028014098
#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0, f = 0; char c = 0;
    while (!isdigit(c)) f |= c == '-', c = getchar();
    while (isdigit(c)) x = (x << 3) + (x << 1) + (c & 15), c = getchar();
    return f ? -x : x;
}

signed main() {
    for (int T = read(); T --;) {
    int l1 = read(), l2 = read(), l3 = read();
    if (l1 > l2) swap(l1, l2);
    if (l1 > l3) swap(l1, l3);
    if (l2 > l3) swap(l2, l3);
    if (l1 + l2 == l3) {
        puts("YES");
    } else {
        if (l1 == l2 && l3 % 2 == 0 ||
            l2 == l3 && l1 % 2 == 0)
            puts("YES");
        else puts("NO");
    }}
    return 0;
}