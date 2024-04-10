#include <bits/stdc++.h>

const int N = 2000005;

int fenw[N];

void modify(int x, int v) {
    while (x < N) fenw[x] += v, x = (x | (x - 1)) + 1;
}

int find_sum(int x) {
    int v = 0;
    while (x > 0) v += fenw[x], x &= x - 1;
    return v;
}

int k;
int a[N], b[N], dir[N];

std::vector<int> ret;
std::vector<int> g[N];

void solve(int root, int to) {
    if (root > to) return;
    if (root == to) return ret.push_back(root);
    int sz = g[root].size();
    int sfrom = root;
    int sto = to;
    for (int q = 0; q < sz; ++q) {
        int j = g[root][q];
        if (dir[j] == 0 && b[j] > sfrom) sfrom = b[j];
        if (dir[j] == 1 && b[j] - 1 < sto) sto = b[j] - 1;
        modify(a[j], -1), modify(b[j], 1);
    }
    int parity = 0;
    while (sfrom <= sto) {
        if (parity) {
            if (find_sum(sfrom) == 0) {
                solve(root + 1, sfrom);
                ret.push_back(root);
                solve(sfrom + 1, to);
                return;
            }
            ++sfrom;
        } else {
            if (find_sum(sto) == 0) {
                solve(root + 1, sto);
                ret.push_back(root);
                solve(sto + 1, to);
                return;
            }
            --sto;
        }
        parity ^= 1;
    }
    std::cout << "IMPOSSIBLE" << '\n';
    exit(0);
}

int main() {
    int n;
    scanf("%d %d", &n, &k);
    char foo[42];
    for (int i = 1; i <= n; ++i) fenw[i] = 0, g[i].clear();
    for (int i = 0; i < k; ++i) {
        std::cin >> a[i] >> b[i] >> foo;
        if (a[i] < 1 || a[i] > n || b[i] < 1 || b[i] > n || b[i] <= a[i]) {
            puts("IMPOSSIBLE");
            return 0;
        }
        dir[i] = (foo[0] == 'L' ? 0 : 1);
        modify(a[i], 1), modify(b[i], -1);
        g[a[i]].push_back(i);
    }
    ret.clear(), solve(1, n);
    for (int i = 0; i < n; ++i) std::cout << ret[i] << " \n"[i == n - 1];
    return 0;
}