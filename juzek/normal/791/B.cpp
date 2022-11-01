#include <cstdio>

int oj[150007];
int ile[150007];
int liczebnosc[150007];

int find(int a) {
    if (oj[a] == a)
        return a;
    oj[a] = find(oj[a]);
    return oj[a];
}

void unioner(int a, int b) {
    a = find(a);
    b = find(b);
    oj[a] = b;
}

int main() {
    int N, M;
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; i++) {
        oj[i] = i;
    }
    int a, b;
    while (M--) {
        scanf("%d%d", &a, &b);
        ile[a]++;
        ile[b]++;
        unioner(a, b);
    }
    for (int i = 1; i <= N; i++) {
        liczebnosc[find(i)]++;
    }
    for (int i = 1; i <= N; i++) {
        if (ile[i] != liczebnosc[find(i)] - 1) {
            printf("NO");
            return 0;
        }
    }
    printf("YES");
    return 0;
}