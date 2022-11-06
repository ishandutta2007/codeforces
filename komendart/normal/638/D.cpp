#include <bits/stdc++.h>

using namespace std;

const int maxn = 105;

int n, m, k;
int table[maxn][maxn][maxn];

int get(int x, int y, int z) {
    if (x < 0 || y < 0 || z < 0 || x >= n || y >= m || z >= k) return 0;
    return table[x][y][z];
}

int get(const vector<int> &pos) {
    return get(pos[0], pos[1], pos[2]);
}

bool check(int x, int y, int z) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            vector<int> a = {x, y, z};
            vector<int> b = {x, y, z};
            vector<int> c = {x, y, z};
            a[i]--; b[j]++; c[i]--; c[j]++;
            if (get(a) && get(b) && (i == j || !get(c))) {
                return true;
            }
        }
    }
    return false;
}

char str[maxn];

int main() {
    scanf("%d%d%d", &n, &m, &k);
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            scanf("%s", str);
            for (int z = 0; z < k; z++) {
                table[x][y][z] = str[z] - '0';
            }
        }
    }

    int ans = 0;
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            for (int z = 0; z < k; z++) {
                if (table[x][y][z] && check(x, y, z)) {
                    ans++;
                }
            }
        }
    }

    printf("%d\n", ans);
}