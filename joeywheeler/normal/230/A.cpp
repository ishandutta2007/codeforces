#include <cstdio>
#include <algorithm>

#define N 1010

using namespace std;

struct dragon {
    int s, b;

    void init() {
        scanf("%d %d", &s, &b);
    }
    
    bool operator<(const dragon &o) const {
        return s < o.s;
    }
};

dragon d[N];

int main() {
    int n, s;
    scanf("%d %d", &s, &n);
    for (int i = 0; i < n; i++) {
        d[i].init();
    }
    sort(d, d+n);
    for (int i = 0; i < n; i++) {
        if (s <= d[i].s) {
            printf("NO\n");
            return 0;
        } else {
            s += d[i].b;
        }
    }
    printf("YES\n");
}