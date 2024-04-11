#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 100111;
int a[N], t[N], r[N];
bool canDisappearFirst[N];
int called[N];
int lastCalled[N];
int freePlaces[N];

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int m, k;
        scanf("%d%d", &m, &k);
        freePlaces[0] = 0;
        for (int i = 1; i <= k; ++i) {
            scanf("%d", a + i);
            called[i] = 0;
            lastCalled[i] = -1;
        }
        int firstDisappointed = -1;
        for (int i = 0; i + 1 < m; ++i) {
            scanf("%d%d", t + i, r + i);

            called[ t[i] ] += 1;
            lastCalled[ t[i] ] = i;
            if (i) {
                freePlaces[i] = freePlaces[i - 1];
            }

            if (r[i] && firstDisappointed == -1) {
                firstDisappointed = i;
            }
            if (!t[i]) {
                freePlaces[i] += 1;
            }
        }

        int wholeFreePlaces = freePlaces[m - 2];
        if (firstDisappointed != -1) {
            for (int i = 1; i <= k; ++i) {
                canDisappearFirst[i] = false;
                if (lastCalled[i] >= firstDisappointed) {
                    // can't be first to disappear
                    // cause we've given afterwards
                    continue;
                }

                // actually can't be disappointed at first step (a[i] >= 1)
                int gotFreePlaces = (firstDisappointed == 0 ? 0 : freePlaces[firstDisappointed - 1]);
                if (gotFreePlaces + called[i] >= a[i]) {
                    // we need enough places to disappear
                    canDisappearFirst[i] = true;
                }
            }

            int minNeedToDisappear = 1e9;
            for (int i = 1; i <= k; ++i) {
                if (canDisappearFirst[i]) {
                    minNeedToDisappear = min(minNeedToDisappear, a[i] - called[i]);
                }
            }

            for (int i = 1; i <= k; ++i) {
                if (canDisappearFirst[i] || called[i] + wholeFreePlaces - minNeedToDisappear >= a[i]) {
                    putchar('Y');
                } else {
                    putchar('N');
                }
            }
        } else {
            for (int i = 1; i <= k; ++i) {
                if (called[i] + wholeFreePlaces >= a[i]) {
                    putchar('Y');
                } else {
                    putchar('N');
                }
            }
        }

        puts("");
    }

    return 0;
}