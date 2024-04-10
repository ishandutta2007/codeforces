#include <cstdio>
#include <cstring>
#include <cstdlib>
int x1, y1, x2, y2;

bool judge() {
    if (y1 == y2) {
    int len = abs(x2 - x1);
    printf("%d %d %d %d\n", x1, y1 + len, x2, y2 + len);
    }
    else if (x1 == x2) {
    int len = abs(y1 - y2);
    printf("%d %d %d %d\n", x1 + len, y1, x2 + len, y2);
    }
    else {
    if (abs(x1 - x2) != abs(y1 - y2)) return false;
    printf("%d %d %d %d\n", x1, y2, x2, y1);
    }
    return true;
}

int main() {
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    if (!judge()) printf("-1\n");
    
    return 0;
}