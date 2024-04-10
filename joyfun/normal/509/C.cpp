#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 305;

int n, b[N];
int num[10005], nn;

void find(int cha) {
    for (int i = 0; i < nn; i++) {
        if (cha > 0) {
            num[i] += 1;
            for (int j = i; j < nn; j++) {
                num[j + 1] += num[j] / 10;
                num[j] %= 10;
            }
            if (num[nn]) nn++;
            return;
        }
        cha += num[i];
        num[i] = 0;
    }
    num[nn++] = 1;
}

int main() {
    while (~scanf("%d", &n)) {
        nn = 1;
        memset(num, 0, sizeof(num));
        for (int i = 0; i < n; i++)
            scanf("%d", &b[i]);
        for (int i = 0; i < n; i++) {
            int tmp = 0;
            for (int i = 0; i < nn; i++)
                tmp += num[i];
            int cha = b[i] - tmp;

            if (cha <= 0) find(cha);

            tmp = 0;
            for (int i = 0; i < nn; i++)
                tmp += num[i];
            cha = b[i] - tmp;
            for (int i = 0; i < nn; i++) {
                if (num[i] + cha <= 9) {
                    num[i] += cha;
                    cha = 0;
                    break;
                } else {
                    cha = max(cha - 9 + num[i], 0);
                    num[i] = 9;
                }
            }
            if (cha) {
                while (cha) {
                    num[nn++] = min(cha, 9);
                    cha = max(cha - 9, 0);
                }
            }
            for (int i = nn - 1; i >= 0; i--)
                printf("%d", num[i]);
            printf("\n");
        }
    }
    return 0;
}