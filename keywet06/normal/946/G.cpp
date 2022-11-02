#include <bits/stdc++.h>

const int N = 400005;
const int M = 2097152;

int n, res;
int a[N];
int mx[2][M];
std::vector<int> un;

int Get(int s, int v, int l, int r, int a, int b) {
    if (l == a && r == b) {
        return mx[s][v];
    } else {
        int m = l + r >> 1;
        if (b <= m) return Get(s, 2 * v, l, m, a, b);
        if (m + 1 <= a) return Get(s, 2 * v + 1, m + 1, r, a, b);
        return std::max(Get(s, 2 * v, l, m, a, m), Get(s, 2 * v + 1, m + 1, r, m + 1, b));
    }
}

void Update(int s, int v, int l, int r, int x, int val) {
    mx[s][v] = std::max(mx[s][v], val);
    if (l < r) {
        int m = l + r >> 1;
        if (x <= m) {
            Update(s, 2 * v, l, m, x, val);
        } else {
            Update(s, 2 * v + 1, m + 1, r, x, val);
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        a[i] -= i;
        un.push_back(a[i]);
        un.push_back(a[i] + 1);
    }
    sort(un.begin(), un.end());
    un.erase(unique(un.begin(), un.end()), un.end());
    for (int i = 0; i < n; ++i) a[i] = lower_bound(un.begin(), un.end(), a[i]) - un.begin();
    int lst = int(un.size()) - 1;
    for (int i = 0; i < n; ++i) {
        int val;
        if (i + 1 < n) {
            val = std::max(Get(0, 1, 0, lst, 0, a[i + 1] + 1), Get(1, 1, 0, lst, 0, a[i + 1] + 1)) + 1;
            res = std::max(res, val);
            Update(1, 1, 0, lst, a[i + 1] + 1, val);
        }
        val = Get(0, 1, 0, lst, 0, a[i]) + 1;
        res = std::max(res, val);
        Update(0, 1, 0, int(un.size()) - 1, a[i], val);
    }
    std::cout << std::max(0, n - 1 - res) << std::endl;
    return 0;
}