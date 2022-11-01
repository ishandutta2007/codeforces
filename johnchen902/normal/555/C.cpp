#include <cstdio>
#include <map>

using namespace std;

map<int, pair<int, char>> aa;

int qu(int n, int x, int y) {
    auto p = aa.lower_bound(x);
    if(p == aa.end()) {
        return y;
    } else {
        if(p->first == x) return 0;

        if(p->second.second == 'L') {
            return y - (n + 1 - p->first);
        } else {
            return p->second.first + (y - (n + 1 - p->first));
        }
    }
}

int ql(int n, int x, int y) {
    auto p = aa.upper_bound(x);
    if(p == aa.begin()) {
        return x;
    } else {
        if((--p)->first == x) return 0;

        if(p->second.second == 'U') {
            return x - p->first;
        } else {
            return p->second.first + (x - p->first);
        }
    }
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);

    for(int i = 0; i < q; i++) {
        int x, y;
        char cmd[2];
        scanf("%d %d %1s", &x, &y, cmd);
        if(cmd[0] == 'U') {
            int ans = qu(n, x, y);
            aa.insert({x, {ans, 'U'}});
            printf("%d\n", ans);
        } else {
            int ans = ql(n, x, y);
            aa.insert({x, {ans, 'L'}});
            printf("%d\n", ans);
        }
    }
}