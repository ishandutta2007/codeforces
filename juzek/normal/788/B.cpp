#include <cstdio>
#include <vector>

int ile[1000007];
bool jest[1000007];
int oj[1000007];

int ileZb;

int find(int a) {
    if (oj[a] == a)
        return a;
    return oj[a] = find(oj[a]);
}

int main() {
    int N, M;
    scanf("%d%d", &N, &M);
    ileZb = N;
    for (int i = 1; i <= N; i++)
        oj[i] = i;
    int ileC = 0;
    for (int i = 0; i < M; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        if (a != b) {
            ile[a]++;
            ile[b]++;
        } else {
            ileC++;
            jest[a] = true;
        }
        a = find(a), b = find(b);
        if (a != b) {
            ileZb--;
            oj[a] = b;
        }
    }
    for (int i = 1; i <= N; i++)
        if (ile[i] == 0 && !jest[i])
            ileZb--;
    if (ileZb > 1) {
        printf("0");
        return 0;
    }
    long long wyn = 0;
    for (int i = 1; i <= N; i++) {
        long long ter = ile[i];
        ter *= ter - 1;
        ter /= 2;
        wyn += ter;
    }
    wyn += (long long) ileC * (M - ileC) + (long long) ileC * (ileC - 1) / 2;
    printf("%lld", wyn);
    return 0;
}