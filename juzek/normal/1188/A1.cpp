#include <cstdio>
#include <vector>

std::vector<int> v[100007];

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 1; i < N; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for (int i = 1; i <= N; i++) {
        if (v[i].size() == 2) {
            printf("NO");
            return 0;
        }
    }
    printf("YES");
    return 0;
}