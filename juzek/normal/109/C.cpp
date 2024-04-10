#include <cstdio>
#include <vector>

std::vector<std::pair<int, bool>> v[100007];
int ile[100007];
int syn[100007];

void dfs(int a, int oj) {
    syn[a] = 1;
    for (auto it : v[a]) {
        if (it.first != oj) {
            dfs(it.first, a);
            syn[a] += syn[it.first];
            if (it.second)
                ile[a] += syn[it.first];
            else
                ile[a] += ile[it.first];
        }
    }
}

int N;
long long wyn = 0;

void dfs2(int a, int oj, int gora) {
    int sum = ile[a] + gora;
    wyn += (long long) sum * sum - sum;
    for (auto it : v[a]) {
        if (it.first != oj) {
            if (it.second)
                dfs2(it.first, a, N - syn[it.first]);
            else
                dfs2(it.first, a, sum - ile[it.first]);
        }
    }
}

int main() {
    scanf("%d", &N);
    int a, b, c;
    for (int i = 1; i < N; i++) {
        scanf("%d%d%d", &a, &b, &c);
        bool cc = true;
        if (c == 0)
            cc = false;
        else {
            while (c != 0) {
                if (c % 10 != 4 && c % 10 != 7)
                    cc = false;
                c /= 10;
            }
        }
        v[a].emplace_back(b, cc);
        v[b].emplace_back(a, cc);
    }
    dfs(1, -1);
    dfs2(1, -1, 0);
    printf("%lld", wyn);
    return 0;
}