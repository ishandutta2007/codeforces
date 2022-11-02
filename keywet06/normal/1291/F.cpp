#include <bits/stdc++.h>

int n, k;

std::vector<bool> uni;

void query(int x) {
    if (!uni[x]) return;
    std::cout << "? " << x + 1 << std::endl;
    char res;
    std::cin >> res;
    if (res == 'Y') uni[x] = false;
}

void reset() { std::cout << "R" << std::endl; }

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> k;
    uni.assign(n, true);
    if (k == 1) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                reset();
                query(j);
                query(i);
            }
        }
    } else {
        for (int i = 0; i < n; ++i) query(i);
        for (int i = 0; i < n; i += k) {
            for (int j = 0; j < i; j += k) {
                reset();
                for (int l = i; l < i + k / 2; ++l) query(l);
                for (int l = j; l < j + k / 2; ++l) query(l);
                for (int l = i + k / 2; l < i + k; ++l) query(l);
                reset();
                for (int l = i + k / 2; l < i + k; ++l) query(l);
                for (int l = j + k / 2; l < j + k; ++l) query(l);
                for (int l = i; l < i + k / 2; ++l) query(l);
            }
        }
    }
    std::cout << "! " << std::accumulate(uni.begin(), uni.end(), 0)
              << std::endl;
    return 0;
}