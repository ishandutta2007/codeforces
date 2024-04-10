#include <bits/stdc++.h>

const int N = 205;

char q0[N], q1[N];
int n, len0, len1, len2, l0, r0, l1, r1, l2, r2, cnt[N], cc[N], f[N];
std::string ans;
std::vector<char> p[N][N];
std::vector<std::vector<std::string>> a, b, c;

void put(int i, char c) {
    ans[i - 1] = c;
}
void put(int i, int j, char c0, char c1) {
    if (i > j) { std::swap(i, j); }
    if (p[i - 1][j - 1].empty()) {
        p[i - 1][j - 1].push_back(c0);
        p[i - 1][j - 1].push_back(c1);
    }
}

void query(int l, int r, std::vector<std::vector<std::string>> &e) {
    std::cout << "? " << l << " " << r << std::endl;
    int tot = (r - l + 1) * (r - l + 2) / 2;
    e.resize(n + 1);
    for (int i = 0; i < tot; i++) {
        std::string res;
        std::cin >> res;
        e[res.size()].push_back(res);
    }
}

void solve(int l, int r, std::vector<std::vector<std::string>> &e) {
    int len = r - l + 1, ccc = len;
    for (int j = 0; j <= 30; j++) { cnt[j] = 0; cc[j] = 0; }
    for (auto s : e[1]) { cnt[s[0] - 'a']++; cc[s[0] - 'a']++; }
    if (len > 1) {
        for (int i = 2, _l = l, _r = r; ; i++) {
            if (ccc == 1) {
                for (int j = 0; j <= 30; j++) {
                    if (cc[j] == 0) { continue; }
                    put(_l, j + 'a');
                }
                break;
            } else if (ccc == 2) {
                char c0 = '?', c1;
                for (int j = 0; j <= 30; j++) {
                    if (cc[j] == 0) { continue; }
                    if (cc[j] == 2) {
                        c0 = j + 'a'; c1 = j + 'a';
                        break;
                    } else if (c0 == '?') {
                        c0 = j + 'a';
                    } else {
                        c1 = j + 'a';
                    }
                }
                put(_l, _r, c0, c1);
                break;
            }
            for (int j = 0; j <= 30; j++) { f[j] = -cnt[j] * i; }
            for (auto s : e[i]) {
                for (int k = 0; k < i; k++) { f[s[k] - 'a']++; }
            }
            for (int j = 2; j < i; j++) {
                f[q0[j] - 'a'] += i; f[q0[j] - 'a'] -= j - 1;
                f[q1[j] - 'a'] += i; f[q1[j] - 'a'] -= j - 1;
            }
            bool flag = false;
            for (int j = 0; j <= 30; j++) {
                if (f[j] != 0) {
                    if (f[j] == -2) {
                        q0[i] = j + 'a'; cc[j]--; ccc--;
                        q1[i] = j + 'a'; cc[j]--; ccc--;
                        break;
                    } else if (flag == false) {
                        q0[i] = j + 'a'; cc[j]--; ccc--; flag = true;
                    } else {
                        q1[i] = j + 'a'; cc[j]--; ccc--;
                    }
                }
            }
            put(_l, _r, q0[i], q1[i]);
            _l++; _r--;
        }
    } else {
        for (int j = 0; j <= 30; j++) {
            if (cc[j] == 0) { continue; }
            put(l, j + 'a');
        }
    }
}

int main() {
    std::cin >> n; ans.resize(n);
    for (int i = 0; i < n; i++) { ans[i] = '?'; }
    if (n <= 3) {
        for (int i = 1; i <= n; i++) {
            if (i == 1) {
                query(i, i, a); ans[i - 1] = a[1][0][0];
            }
            if (i == 2) {
                query(i, i, b); ans[i - 1] = b[1][0][0];
            }
            if (i == 3) {
                query(i, i, c); ans[i - 1] = c[1][0][0];
            }
        }
    } else {
        for (int i = 1; i <= n; i++) {
            if (i > n - i - i) {
                len0 = len1 = i; len2 = n - i - i; break;
            }
        }
        l0 = 1; r0 = l0 + len0;
        l1 = r0; r1 = l1 + len1;
        l2 = r1; r2 = l2 + len2;
        query(l0, r1 - 1, a); solve(l0, r1 - 1, a);
        query(l0, r1 - 2, b); solve(l0, r1 - 2, b);
        for (int i = n; i >= 1; i--) {
            if ((n - i) % 2 == 0 && (n + i) / 2 == r1 - 1) {
                query(i, n, c); solve(i, n, c); break;
            }
        }
        for (int _ = 0; _ < 1000; _++) {
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    if (!p[i][j].empty()) {
                        if (ans[i] == p[i][j][0]) {
                            ans[j] = p[i][j][1];
                        }
                        if (ans[i] == p[i][j][1]) {
                            ans[j] = p[i][j][0];
                        }
                        if (ans[j] == p[i][j][0]) {
                            ans[i] = p[i][j][1];
                        }
                        if (ans[j] == p[i][j][1]) {
                            ans[i] = p[i][j][0];
                        }
                    }
                }
            }
        }
    }
    std::cout << "! " << ans << std::endl;
    return 0;
}