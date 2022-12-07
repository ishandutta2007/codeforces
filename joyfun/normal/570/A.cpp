#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 105;

int cnt[N], tmp[N];

int main() {
    int n, m;
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= n; i++){
        int id = 1;
        for (int j = 1; j <= m; j++) {
            scanf("%d", &tmp[j]);
            if (tmp[id] < tmp[j]) id = j;
        }
        cnt[id]++;
    }
    int id = 1;
    for (int i = 1; i <= m; i++) {
        if (cnt[id] < cnt[i]) id = i;
    }
    printf("%d\n", id);
    return 0;
}