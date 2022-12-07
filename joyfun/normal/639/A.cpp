#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

const int N = 150005;

int n, k, q, t[N];
set<pair<int, int> > s;

int main() {
    scanf("%d%d%d", &n, &k, &q);
    for (int i = 1; i <= n; i++) scanf("%d", &t[i]);
    int tp, x;
    while (q--) {
        scanf("%d%d", &tp, &x);
        if (tp == 1) {
            s.insert(make_pair(t[x], x));
            if (s.size() > k) s.erase(s.begin());
        } else printf("%s\n", s.find(make_pair(t[x], x)) != s.end() ? "YES" : "NO");
    }
    return 0;
}