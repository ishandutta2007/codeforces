// Hydro submission #623c547ff7716b87f5f056b6@1648120959899
#include <bits/stdc++.h>
using namespace std;
 
inline int read() {
    int x = 0, f = 0; char c = 0;
    while (!isdigit(c)) f |= c == '-', c = getchar();
    while (isdigit(c)) x = (x << 3) + (x << 1) + (c & 15), c = getchar();
    return f ? -x : x;
}
 
int a[200010];
 
int main() {
    for (int T = read(); T --;) {
        int n = read(), id = 0, same = 1;
        for (int i = 1; i <= n; i ++) {
            a[i] = read();
            if (i != 1 && a[i - 1] != a[i]) same = 0;
        }
        if (same) printf("%d\n", n);
        else puts("1");
   }
    return 0;
}