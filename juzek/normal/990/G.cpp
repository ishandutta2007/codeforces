#include <cstdio>
#include <vector>

int tab[200007];
std::vector<int> kubelki[200007];
std::vector<int> v[200007];
bool aktywny[200007];
long long ile[200007];
int rozm = 0;
int mobius[200007];

void dfs(int a) {
    rozm++;
    aktywny[a] = false;
    for (auto it : v[a])
        if (aktywny[it])
            dfs(it);
}

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &tab[i]);
        kubelki[tab[i]].push_back(i);
    }
    for (int i = 1; i < N; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for (int i = 1; i <= 200000; i++) {
        for (int w = i; w <= 200000; w += i)
            for (auto it : kubelki[w])
                aktywny[it] = true;
        for (int w = i; w <= 200000; w += i)
            for (auto it : kubelki[w])
                if (aktywny[it]) {
                    dfs(it);
                    ile[i] += ((long long) rozm * (rozm + 1)) / 2;
                    rozm = 0;
                }
    }
    mobius[1] = -1;
    for (int i = 1; i <= 200000; i++) {
        mobius[i] = 0 - mobius[i];
        for (int w = i + i; w <= 200000; w += i)
            mobius[w] += mobius[i];
    }
    for (int i = 1; i <= 200000; i++) {
        long long wyn = 0;
        for (int w = i; w <= 200000; w += i)
            wyn += mobius[w / i] * ile[w];
        if (wyn != 0)
            printf("%d %lld\n", i, wyn);
    }
    return 0;
}