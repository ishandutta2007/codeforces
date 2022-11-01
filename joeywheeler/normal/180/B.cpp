#include <cstdio>
#include <cstring>
#include <vector>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int gdt(int,int);

int gcd(int a, int b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

int t2(int b, int d) {
    int r = 0;
    while (gcd(b,d) != 1) r++, d /= gcd(b,d);
    return d == 1 ? r : 0;
}

bool t6(int b, int d) {
    int D = d;

    int c = 2;
    while (d > 1) {
        int r = 1;
        while (d % c == 0) {
            d /= c;
            r *= c;
        }
        if (r == D) return false;
        if (gdt(b,r) == 7) return false;
        c++;
    }
    return true;
}

int gdt(int b, int d) {
    if (t2(b,d)) return 2;
    else if (b % d == 1) return 3;
    else if (b % d == d-1) return 11;
    else if (t6(b,d)) return 6;
    else return 7;
}

int main() {
    int b, d;
    scanf("%d %d", &b, &d);
    int T = gdt(b,d);
    printf("%d-type\n", gdt(b,d));
    if (T == 2) printf("%d\n", t2(b,d));
}