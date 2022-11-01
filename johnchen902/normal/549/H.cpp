#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

struct Range {
    double l, r;
};

Range mul(Range lhs, Range rhs) {
    Range x;
    x.l = min(lhs.l * rhs.l, min(lhs.r * rhs.l, min(lhs.l * rhs.r, lhs.r * rhs.r)));
    x.r = max(lhs.l * rhs.l, max(lhs.r * rhs.l, max(lhs.l * rhs.r, lhs.r * rhs.r)));
    if((lhs.l <= 0 && lhs.r >= 0) && (rhs.l <= 0 && rhs.r >= 0))
        x.l = min(x.l, 0.), x.r = max(x.r, 0.);
    return x;
}

bool overlap(Range lhs, Range rhs) {
    return !(lhs.r < rhs.l || rhs.r < lhs.l);
}

int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    double l = 0, r = max(abs(a), max(abs(b), max(abs(c), abs(d))));
    for(int i = 0; i < 1000; i++) {
        double x = (l + r) / 2;
        if(overlap(mul({a - x, a + x}, {d - x, d + x}), mul({b - x, b + x}, {c - x, c + x})))
            r = x;
        else
            l = x;
    }
    printf("%.16f\n", l);
}