#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int x[50];
int y[50];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0; i < 4 * n + 1; ++i) {
        cin >> x[i] >> y[i];
    }
    for (int x1 = 0; x1 <= 50; ++x1) {
        for (int x2 = x1 + 1; x2 <= 50; ++x2) {
            for (int y1 = 0; y1 <= 50; ++y1) {
                for (int y2 = y1 + 1; y2 <= 50; ++y2) {
                    if (x2 - x1 != y2 - y1) continue;
                    int cnt = 0;
                    int C[4] = {};
                    for (int i = 0; i < 4 * n + 1; ++i) {
                        int c = 1;
                        if (x1 == x[i] && y1 <= y[i] && y[i] <= y2) ++C[0], c = 0;
                        if (x2 == x[i] && y1 <= y[i] && y[i] <= y2) ++C[1], c = 0;
                        if (y1 == y[i] && x1 <= x[i] && x[i] <= x2) ++C[2], c = 0;
                        if (y2 == y[i] && x1 <= x[i] && x[i] <= x2) ++C[3], c = 0;
                        cnt += c;
                    }
                    if (cnt != 1) continue;
                    if (C[0] < n) continue;
                    if (C[1] < n) continue;
                    if (C[2] < n) continue;
                    if (C[3] < n) continue;
                    for (int i = 0; i < 4 * n + 1; ++i) {
                        if (x1 == x[i] && y1 <= y[i] && y[i] <= y2) continue;
                        if (x2 == x[i] && y1 <= y[i] && y[i] <= y2) continue;
                        if (y1 == y[i] && x1 <= x[i] && x[i] <= x2) continue;
                        if (y2 == y[i] && x1 <= x[i] && x[i] <= x2) continue;
                        printf("%d %d\n", x[i], y[i]);
                        return 0;
                    }
                }
            }
        }
    }
    return 0;
}