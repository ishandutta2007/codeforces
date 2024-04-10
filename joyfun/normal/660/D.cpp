#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <map>
using namespace std;

const int N = 2005;
int x[N], y[N];
map<pair<int, int>, int> s;

int main() {
    int n;
    scanf("%d", &n);
    long long ans = 0;
    for (int i = 1; i <= n; i++) scanf("%d%d", &x[i], &y[i]);
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            ans += s[make_pair(x[j] + x[i], y[j] + y[i])]++;
        }
    }
    printf("%lld\n", ans);
    return 0;
}