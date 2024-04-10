#include <bits/stdc++.h>
using namespace std;

#define INF (1<<30)

#define N 1111

int times[N][5];
int vs[5];
int score(int i) {
    int sc = 0;
    for (int j = 0; j < 5; j++) {
        if (times[i][j] != -1) {
            sc += (vs[j] + 1) * (250 - times[i][j]);
        }
    }
    return sc;
}

bool wins[6*6*6*6*6];
bool can[5][6];
int solved[5];
int fr[7] = {1, 2, 4, 8, 16, 32};
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            scanf("%d", &times[i][j]);
            if (times[i][j] != -1) solved[j]++;
        }
    }

    int ans = INF;

    for (int v = 0; v < 6*6*6*6*6; v++) {
        for (int i = 0, w = v; i < 5; i++, w /= 6) {
            vs[i] = w % 6;
        }
        wins[v] = score(0) > score(1);
    }
    for (int people = 0; people < 5111; people++) {
        for (int j = 0; j < 5; j++) {
            int mern = times[0][j] != -1 ? people : 0;
            for (int k = 0; k < 6; k++) {
                int lf = max(0, k == 5 ? 0 : (n + people) / fr[k + 1] - solved[j] + 1);
                int rg = min(mern, (n + people) / fr[k] - solved[j]);
                can[j][k] = lf <= rg;
            }
        }
        bool good = false;
        for (int v = 0; v < 6*6*6*6*6; v++) {
            if (wins[v]) {
                good = true;
                for (int i = 0, w = v; i < 5; i++, w /= 6) {
                    if (!can[i][w % 6]) {
                        good = false;
                        break;
                    }
                }
                if (good) {
                    break;
                }
            }
        }
        if (good) {
            ans = people;
            break;
        }
    }

    printf("%d\n", ans < INF ? ans : -1);
}