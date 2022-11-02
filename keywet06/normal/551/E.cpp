#include <bits/stdc++.h>

const int N = 500005;
const int B = 715;
const int INF = 1000000005;

int arr[N], lzy[B], whb[N];

std::set<std::pair<int, int>> mst[B];

int main(void) {
    int n, q;
    std::cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
        whb[i] = i / B;
        mst[whb[i]].insert(std::make_pair(arr[i], i));
    }
    while (q--) {
        int t;
        std::cin >> t;
        if (t == 1) {
            int l, r, x;
            std::cin >> l >> r >> x, --l, --r;
            for (int i = l; i <= r;) {
                if (whb[i] == whb[l] || whb[i] == whb[r]) {
                    mst[whb[i]].erase(std::make_pair(arr[i], i));
                    arr[i] = std::min(arr[i] + x, INF);
                    mst[whb[i]].insert(std::make_pair(arr[i], i));
                    ++i;
                } else {
                    lzy[whb[i]] = std::min(lzy[whb[i]] + x, INF);
                    i += B;
                }
            }
        } else {
            int x, le = -1, ri = n;
            std::cin >> x;
            for (int i = 0; i <= n / B && le == -1; ++i) {
                auto it = mst[i].lower_bound(std::make_pair(x - lzy[i], 0));
                if (it != mst[i].end() && it->first == x - lzy[i]) le = it->second;
            }
            for (int i = n / B; i >= 0 && ri == n; --i) {
                auto it = mst[i].lower_bound(std::make_pair(x - lzy[i] + 1, 0));
                if (it != mst[i].begin() && prev(it)->first == x - lzy[i]) ri = prev(it)->second;
            }
            if (le == -1 || ri == n) {
                std::cout << -1 << "\n";
            } else {
                std::cout << ri - le << "\n";
            }
        }
    }
    return 0;
}