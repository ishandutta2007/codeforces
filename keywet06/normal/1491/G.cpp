#include <bits/stdc++.h>

const int N = 1000005;

bool f[N], vis[N];

int cnt, c, n;
int X[N], Y[N], h[N], sz[N], p[N];

void print(int x, int y) {
    X[++cnt] = std::min(x, y), Y[cnt] = std::max(x, y), std::swap(p[x], p[y]);
    p[x] = -p[x], p[y] = -p[y];
}

void flush() {
    std::cout << cnt << std::endl;
    for (int i = 1; i <= cnt; ++i) std::cout << X[i] << ' ' << Y[i] << '\n';
    return;
}

int main() {
    std::cin >> n;
    for (int i = 1; i <= n; ++i) std::cin >> p[i];
    for (int i = 1; i <= n; ++i) {
        if (!vis[i] && (p[i] != i)) {
            int id = i, cnt = 0;
            while (!vis[id]) vis[id] = 1, ++cnt, id = p[id];
            h[++c] = id, sz[c] = cnt;
        }
    }
    while (c >= 2) {
        int A = h[c], B = h[c - 1];
        print(A, B);
        while (abs(p[A]) != B) print(A, abs(p[A]));
        while (abs(p[B]) != A) print(B, abs(p[B]));
        print(A, B);
        c -= 2;
    }
    if (c) {
        if (sz[c] == 2) {
            for (int i = 1; i <= n; ++i) {
                if (p[i] == i) {
                    int A = i, B = h[1], cnt = p[B];
                    print(A, B), print(A, cnt), print(A, B);
                    break;
                }
            }
        } else {
            int A = h[1], B = p[A], cnt = p[B];
            print(A, B), print(B, cnt);
            while (abs(p[A]) != B) print(A, abs(p[A]));
            while (abs(p[B]) != A) print(B, abs(p[B]));
            print(A, B);
        }
    }
    flush();
    return 0;
}