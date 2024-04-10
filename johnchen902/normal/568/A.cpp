#include <cstdio>
#include <algorithm>
using namespace std;
bool oj(int q) {
    if(q == 2) return 1;
    if(q % 2 == 0) return 0;
    for(int a = 3; a * a <= q; a += 2) if(q % a == 0) return 0;
    return 1;
}
bool ok(int q) {
    int x = q, z = 0;
    while(x) z = z * 10 + x % 10, x /= 10;
    return q == z;
}
int main() {
    int p, q;
    scanf("%d %d", &p, &q);
    int a = 0, b = 1, oo = 1;
    for(int i = 2; i <= 1179858; i++) {
        if(oj(i)) a++;
        if(ok(i)) b++;
        if(q * a <= p * b) oo = i;
    }

    printf("%d\n", oo);
}