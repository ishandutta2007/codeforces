#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;

struct Point {
    int x, y;
    void read() {
        scanf("%d%d", &x, &y);
    }
} p[3], s[3];

int id[3];

int get() {
    if (s[0].x == s[1].x && s[1].x == s[2].x) return 1;
    if (s[0].y == s[1].y && s[1].y == s[2].y) return 1;
    if (s[0].x == s[1].x && (s[2].y <= min(s[0].y, s[1].y) || s[2].y >= max(s[0].y, s[1].y))) return 2;
    if (s[0].y == s[1].y && (s[2].x <= min(s[0].x, s[1].x) || s[2].x >= max(s[0].x, s[1].x))) return 2;
    return 3;
}

int main() {
    for (int i = 0; i < 3; i++) {
        p[i].read();
        id[i] = i;
    }
    int Min = INF;
    do {
        int ans = 0;
        for (int i = 0; i < 3; i++)
            s[i] = p[id[i]];
        Min = min(Min, get());
    } while (next_permutation(id, id + 3));
    printf("%d\n", Min);
    return 0;
}