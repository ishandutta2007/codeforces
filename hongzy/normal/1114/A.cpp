#include <algorithm>
#include <cstdio>
using namespace std;

int x, y, z, a, b, c;

int main() {
    scanf("%d%d%d%d%d%d", &x, &y, &z, &a, &b, &c);
    bool tag = 1;
    a -= x;
    if(a < 0) {
        tag = 0;
    } else {
        b += a;
        b -= y;
        if(b < 0) {
            tag = 0;
        } else {
            c += b;
            c -= z;
            if(c < 0) {
                tag = 0;
            }
        }
    }
    puts(tag ? "YES" : "NO");
    return 0;
}