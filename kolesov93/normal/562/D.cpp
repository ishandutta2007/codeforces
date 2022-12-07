#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

#define prev PREV

const int N = 222222;
int pr[N];

int fs(int x) {
    if (x != pr[x]) pr[x] = fs(pr[x]);
    return pr[x];
}

void un(int x, int y) {
    x = fs(x);
    y = fs(y);
    if (rand())
        pr[x] = y;
    else
        pr[y] = x;
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    int n, q;
    scanf("%d%d", &n, &q);
    set<int> alive;
    for (int i = 1; i <= n; ++i) {
        pr[i] = i;
        alive.insert(i);
    }
    while (q--) {
        int t, x, y;
        scanf("%d%d%d", &t, &x, &y);
        if (t == 1) {
            un(x, y);
        } else
        if (t == 2) {
            while (1) {
                auto i = alive.lower_bound(x);
                if (i == alive.end()) break;
                x = *i;
                if (x >= y) break;
                un(x, x + 1);
                alive.erase(i);
            }
        } else
        if (t == 3) {
            puts((fs(x) == fs(y)) ? "YES" : "NO");
        }
    }
    
    return 0;
}