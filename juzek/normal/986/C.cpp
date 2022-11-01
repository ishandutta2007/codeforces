#include <cstdio>
#include <vector>
#include <cstring>

bool odw[4194304 * 2];
std::vector<int> wejscie;

int pot = 1;

void dfs(int a) {
    odw[a] = true;
    if (a >= pot) {
        if (!odw[a - pot])
            dfs(a - pot);
    } else {
        for (int b = 1; b < pot; b *= 2)
            if ((a & b) == 0 && !odw[a ^ b])
                dfs(a ^ b);
        if (!odw[pot + pot - a - 1])
            dfs(pot + pot - a - 1);
    }
}

int main() {
    int N, M;
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; i++)
        pot *= 2;
    for (int i = 0; i < pot; i++)
        odw[i + pot] = true;
    for (int i = 0; i < M; i++) {
        int a;
        scanf("%d", &a);
        wejscie.push_back(a);
        odw[a + pot] = false;
    }
    int odp = 0;
    for (int i = 0; i < M; i++) {
        int a = wejscie[i];
        if (!odw[a + pot]) {
            dfs(a + pot);
            odp++;
        }
    }
    printf("%d", odp);
    return 0;
}