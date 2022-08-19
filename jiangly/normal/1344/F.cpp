#include <bits/stdc++.h>
constexpr int N = 1e3;
int n, k, cnt;
std::bitset<2 * N> a[2 * N];
int t[2 * N], pos[N], b[2 * N], x[2 * N];
int colorId(char c) {
    if (c == 'W') {
        return 0;
    } else if (c == 'R') {
        return 1;
    } else if (c == 'Y') {
        return 2;
    } else {
        return 3;
    }
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        t[2 * i] = 1;
        t[2 * i + 1] = 2;
    }
    for (int i = 0; i < k; ++i) {
        std::string opt;
        std::cin >> opt;
        int m;
        std::cin >> m;
        for (int j = 0; j < m; ++j) {
            std::cin >> pos[j];
            --pos[j];
        }
        if (opt == "mix") {
            char res;
            std::cin >> res;
            int c = colorId(res);
            for (int j = 0; j < m; ++j) {
                int p = pos[j];
                a[cnt][2 * p] = t[2 * p] & 1;
                a[cnt][2 * p + 1] = t[2 * p] >> 1;
            }
            b[cnt++] = c & 1;
            for (int j = 0; j < m; ++j) {
                int p = pos[j];
                a[cnt][2 * p] = t[2 * p + 1] & 1;
                a[cnt][2 * p + 1] = t[2 * p + 1] >> 1;
            }
            b[cnt++] = c >> 1;
        } else if (opt == "RY") {
            for (int j = 0; j < m; ++j) {
                int p = pos[j];
                std::swap(t[2 * p], t[2 * p + 1]);
            }
        } else if (opt == "RB") {
            for (int j = 0; j < m; ++j) {
                int p = pos[j];
                t[2 * p + 1] ^= t[2 * p];
            }
        } else {
            for (int j = 0; j < m; ++j) {
                int p = pos[j];
                t[2 * p] ^= t[2 * p + 1];
            }
        }
    }
    int r = 0;
    for (int i = 0; i < 2 * n && r < cnt; ++i) {
        for (int j = r; j < cnt; ++j) {
            if (a[j][i]) {
                std::swap(a[j], a[r]);
                std::swap(b[j], b[r]);
                break;
            }
        }
        if (!a[r][i])
            continue;
        for (int j = 0; j < cnt; ++j) {
            if (j != r && a[j][i]) {
                a[j] ^= a[r];
                b[j] ^= b[r];
            }
        }
        ++r;
    }
    for (int i = r; i < cnt; ++i) {
        if (b[i]) {
            std::cout << "NO\n";
            return 0;
        }
    }
    for (int i = 0; i < r; ++i) {
        int j = 0;
        while (!a[i][j])
            ++j;
        x[j] = b[i];
        for (int k = j + 1; k < 2 * n; ++k)
            if (a[i][k])
                x[j] ^= x[k];
    }
    std::cout << "YES\n";
    for (int i = 0; i < n; ++i) {
        int c = x[2 * i] | x[2 * i + 1] << 1;
        std::cout << ".RYB"[c];
    }
    std::cout << "\n";
    return 0;
}