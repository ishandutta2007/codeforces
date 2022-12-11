#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

int n, m, k, ans, a[100010];
vector<int> b;

int main() {
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 1; i <= n; i ++) {
        scanf("%d", &a[i]); ans ++;
        if(i > 1) b.push_back(a[i] - a[i - 1] - 1);
    }
    sort(b.begin(), b.end());
    int d = n, i = 0;
    while(d > k) {
        ans += b[i ++];
        d --;
    }
    printf("%d\n", ans);
    return 0;
}