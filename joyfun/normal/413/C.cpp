#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int N = 10000005;
int n, m;
long long sum, Max, vis[N];
struct Num {
    long long num;
    int vis;
} num[N];

bool cmp(Num a, Num b) {
    return a.num > b.num;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
    scanf("%lld", &num[i].num);
    sum += num[i].num;
    Max = max(Max, num[i].num);
    }
    int v;
    for (int i = 0; i < m; i++) {
    scanf("%d", &v);
    sum -= num[v - 1].num;
    num[v - 1].vis = 1;
    }
    sort(num, num + n, cmp);
    for (int i = 0; i < n; i++) {
    if (num[i].vis) {
        if (sum >= num[i].num)
        break;
        sum += num[i].num;
        m--;
    }
    }
    for (int i = 0; i < m; i++)
    sum *= 2;
    printf("%lld\n", sum);
    return 0;
}