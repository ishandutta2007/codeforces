#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

long long Ax, Ay, Bx, By, Cx, Cy;

bool check(long long Cx, long long Cy) {
    long long dx = Bx - Ax;
    long long dy = By - Ay;
    if (dx == 0 && dy == 0) return true;
    if (Cx == 0 && Cy == 0) return false;
    return (dx * Cx + dy * Cy) % (Cx * Cx + Cy * Cy) == 0;
}

bool judge() {
    for (int i = 0; i < 4; i++) {
        if (check(Cx, Cy) && check(-Cy, Cx)) return true;
        long long tmp = Ax;
        Ax = -Ay;
        Ay = tmp;
    }
    return false;
}

int main() {
    scanf("%lld%lld%lld%lld%lld%lld", &Ax, &Ay, &Bx, &By, &Cx, &Cy);
    printf("%s\n", judge() ? "YES" : "NO");
    return 0;
}