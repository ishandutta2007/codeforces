#include <cstdio>
#include <cstring>

const int z = 1024 * 512;

int maxpot[1000007];
int tab[1000007];
int drzewo[z * 2][20];
int temp[20];

void polacz(int* a, int* b, int* out) {
    if (a != out)
        memcpy(out, a, sizeof(int) * 20);
    for (int i = 19; i >= 0; i--) {
        int ter = b[i];
        while (ter != 0) {
            int m = maxpot[ter];
            if (out[m] == 0) {
                int p = 1 << m;
                for (int w = 0; w < m; w++)
                    if (ter & (1 << w))
                        ter ^= out[w];
                out[m] = ter;
                for (int w = m + 1; w < 20; w++)
                    if ((out[w] & p))
                        out[w] ^= ter;
                break;
            }
            ter ^= out[m];
        }
    }
}

int get(int a, int b) {
    a += z - 1, b += z + 1;
    memset(temp, 0, sizeof(temp));
    while (a != b - 1) {
        if (a % 2 == 0)
            polacz(temp, drzewo[a + 1], temp);
        if (b % 2 == 1)
            polacz(temp, drzewo[b - 1], temp);
        a /= 2, b /= 2;
    }
    int odp = 0;
    for (int i = 0; i < 20; i++)
        odp ^= temp[i];
    return odp;
}

int main() {
    int ter = -1;
    for (int i = 1; i <= 1000000; i++) {
        if ((i & (i - 1)) == 0)
            ter++;
        maxpot[i] = ter;
    }
    int N;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &tab[i]);
        drzewo[i + z][maxpot[tab[i]]] = tab[i];
    }
    for (int i = z - 1; i >= 1; i--)
        polacz(drzewo[i * 2], drzewo[i * 2 + 1], drzewo[i]);
    int M;
    scanf("%d", &M);
    while (M--) {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", get(a, b));
    }
    return 0;
}