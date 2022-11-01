#include <cstdio>
using namespace std;
bool solve(int a, int b, int c, int d, int e, int f) {
    if (a * c * e < b * d * f)
        return true;
    if (a == 0 && b > 0 && d > 0)
        return true;
    if (c == 0 && d > 0)
        return true;
    return false;
}
int main() {
    int a, b, c, d, e, f;
    scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);
    puts(solve(a, b, c, d, e, f) ? "Ron" : "Hermione");
}