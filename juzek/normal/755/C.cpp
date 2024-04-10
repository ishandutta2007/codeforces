#include <cstdio>

int oj[10007];

int find(int a) {
    if (oj[a] == a)
        return a;
    oj[a] = find(oj[a]);
    return oj[a];
}

void unio(int a, int b) {
    a = find(a);
    b = find(b);
    oj[a] = b;
}

bool b[10007];

int main() {
    int N;
    scanf("%d", &N);
    int a;
    for (int i = 1; i <= N; i++)
        oj[i] = i;
    for (int i = 1; i <= N; i++) {
        scanf("%d", &a);
        unio(i, a);
    }
    int wyn = 0;
    for (int i = 1; i <= N; i++) {
        int q = find(i);
        wyn += !b[q];
        b[q] = true;
    }
    printf("%d", wyn);
    return 0;
}