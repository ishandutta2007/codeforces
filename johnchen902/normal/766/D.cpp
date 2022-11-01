#include <cstdio>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
namespace {
int a[200000];
int find(int x) {
    return a[x] == -1 ? x : (a[x] = find(a[x]));
}
void join(int x, int y) {
    x = find(x), y = find(y);
    if(x != y)
        a[x] = y;
}
bool same(int x, int y) {
    return find(x) == find(y);
}
}
int main() {
    int n, m, q;
    scanf("%d %d %d", &n, &m, &q);
    map<string, int> mp;
    for(int i = 0; i < n; i++) {
        char s[21];
        scanf("%s", s);
        mp[s] = i;
    }
    fill(a, a + 2 * n, -1);
    for(int i = 0; i < m; i++) {
        int t;
        char sx[21], sy[21];
        scanf("%d %s %s", &t, sx, sy);
        int x = mp[sx], y = mp[sy];
        if(t == 1) {
            if(same(x, y + n)) {
                puts("NO");
            } else {
                puts("YES");
                join(x, y);
                join(x + n, y + n);
            }
        } else {
            if(same(x, y)) {
                puts("NO");
            } else {
                puts("YES");
                join(x, y + n);
                join(x + n, y);
            }
        }
    }
    for(int i = 0; i < q; i++) {
        char sx[21], sy[21];
        scanf("%s %s", sx, sy);
        int x = mp[sx], y = mp[sy];
        if(same(x, y)) {
            puts("1");
        } else if(same(x, y + n)) {
            puts("2");
        } else {
            puts("3");
        }
    }

}