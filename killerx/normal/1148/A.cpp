#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read() {
    int x = 0, f = 1, c = getchar();
    for (;!isdigit(c);c = getchar()) if (c == '-') f = 0;
    for (; isdigit(c);c = getchar()) x = x * 10 + c - 48;
    return f ? x : -x;
}
int main() {
    int a, b, c;
    a = read(), b = read(), c = read();
    printf("%lld\n", 2LL * c + 2 * min(a, b) + (a > b || b > a ? 1 : 0));
    return 0;
}