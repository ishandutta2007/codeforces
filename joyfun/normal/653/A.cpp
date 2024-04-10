#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n, t[55];

bool gao(int a, int b, int c) {
    if (a == b) return false;
    if (b == c) return false;
    if (a == c) return false;
    if (max(a - b, b - a) > 2) return false;
    if (max(a - c, c - a) > 2) return false;
    if (max(b - c, c - b) > 2) return false;
    return true;
}

bool judge() {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (gao(t[i], t[j], t[k])) return true;
            }
        }
    }
    return false;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &t[i]);
    printf("%s\n", judge() ? "YES" : "NO");
    return 0;
}