#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;

set<int> s[200005];
set<int>::iterator it;

int parent[200005], in[200005];

int find(int x) {
    if (x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

void mg(int l, int r) {
    if (in[l] != in[r]) {
        if (s[in[l]].size() > s[in[r]].size()) swap(l, r);
        int f = in[l];
        for (it = s[f].begin(); it != s[f].end(); it++) {
            int tmp = *it;
            in[tmp] = in[r];
            s[in[r]].insert(tmp);
        }
    }
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        in[i] = i;
        s[i].insert(i);
    }
    parent[n + 1] = n + 1;
    int tp, l, r;
    while (m--) {
        scanf("%d%d%d", &tp, &l, &r);
        if (tp == 1) {
            mg(l, r);

        } else if (tp == 2) {
            for (int i = find(l); i < r; i = find(i)) {
                int nt = find(i + 1);
                parent[i] = nt;
                mg(i, nt);
            }
        } else printf("%s\n", in[l] == in[r] ? "YES" : "NO");
    }
    return 0;
}