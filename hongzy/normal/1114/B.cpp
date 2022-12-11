#include <algorithm>
#include <cstdio>
using namespace std;

typedef long long ll;

const int N = 2e5 + 10;

struct node {
    int x, i;
    bool operator < (const node &b) const {
        return x > b.x;
    }
} a[N];

int n, m, k;
bool use[N];

int main() {
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 1; i <= n; i ++)
        scanf("%d", &a[a[i].i = i].x);
    sort(a + 1, a + n + 1);
    ll ans = 0;
    for(int i = 1; i <= m * k; i ++) use[a[i].i] = 1, ans += a[i].x;
    printf("%I64d\n", ans);
    int cnt = 0, pr = 0;
    for(int i = 1; i <= n; i ++) {
        if(use[i]) {
            cnt ++;
            if(cnt == m) {
                pr ++; cnt = 0;
                printf("%d ", i);
                if(pr == k - 1) break ;
            }
        }
    }
    return 0;
}