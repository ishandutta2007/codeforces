#include <cstdio>
#include <iostream>

int wyn[57];

void printName(int a) {
    bool first = true;
    while (a != 0) {
        if (a%2 == 0) {
            if (!first)
                printf("a");
            else
                printf("A");
        }
        else {
            if (!first)
                printf("b");
            else
                printf("B");
        }
        a /= 2;
        first = false;
    }
    printf(" ");
}

int main() {
    int N, M;
    scanf("%d%d", &N, &M);
    int ter = M;
    for (int i = 0; i < M - 1; i++) {
        wyn[i] = i + 1;
    }
    std::string s;
    for (int i = 0; i <= N - M; i++) {
        std::cin >> s;
        if (s[0] == 'N') {
            wyn[i + M - 1] = wyn[i];
        } else {
            wyn[i + M - 1] = ter;
            ter++;
        }
    }
    for (int i = 0; i < N; i++) {
        printName(wyn[i]);
    }
    return 0;
}