#include <cstdio>
#include <algorithm>

using namespace std;

int heights[300];
bool failed[300][200][300];
int n, k;

bool fix(int i, int prev, int l) {
    if (l < 0) return false;
    if (i == 2 * n + 1) return l == 0;
    if (failed[i][prev][l]) return false;

    if (i % 2 == 0) {
        //this < prev
        if (heights[i] < prev) {
            if (fix(i + 1, heights[i], l)) {
                return true;
            }
        }
    } else {
        //this > prev
        if (heights[i] > prev) {
            if (fix(i + 1, heights[i], l)) {
                return true;
            }
        }
        if (heights[i]-1 > prev) {
            if (fix(i + 1, heights[i]-1, l-1)) {
                heights[i]--;
                return true;
            }
        }
    }
    failed[i][prev][l] = true;
    return false;
}

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < 2 * n + 1; i++) {
        scanf("%d", &heights[i]);
    }
    fix(0, 105, k);
    for (int i = 0; i < 2 * n + 1; i++) {
        printf("%d ", heights[i]);
    }
}