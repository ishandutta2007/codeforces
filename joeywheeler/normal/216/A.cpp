#include <cstdio>

using namespace std;

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    int x = 1, y = 1, z = 1;
    int res = 1;
    while (x < a) {
        res += y + z - 1;
        x++;
    }
    while (y < b) {
        res += x + z - 1;
        y++;
    }
    while (z < c) {
        res += x + y - 1;
        z++;
    }
    printf("%d", res);
}