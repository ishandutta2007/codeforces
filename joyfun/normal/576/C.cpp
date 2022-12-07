#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1000005;

int n;

struct Point {
    int x, y, id;
    void read(int id) {
        this->id = id;
        scanf("%d%d", &x, &y);
    }
    bool operator < (const Point &c) const {
        if (x / 1000 == c.x / 1000) {
            if (x / 1000 % 2) return y > c.y;
            else return y < c.y;
        }
        return x / 1000 < c.x / 1000;
    }
} p[N];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) p[i].read(i + 1);
    sort(p, p + n);
    for (int i = 0; i < n; i++) printf("%d ", p[i].id);
    return 0;
}