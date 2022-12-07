#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

long long m;

long long cal(long long x) {
    return x * x * x;
}

pair<int, long long> ans;

void dfs(long long m, int cnt, long long sum) {
    if (m == 0) {
        ans = max(ans, make_pair(cnt, sum));
        return;
    }
    long long mm = (long long)pow(m, 1.0 / 3);
    while (cal(mm + 1) <= m) mm++;
    dfs(m - cal(mm), cnt + 1, sum + cal(mm));
    if (mm - 1 >= 0) dfs(cal(mm) - 1 - cal(mm - 1), cnt + 1, sum + cal(mm - 1));
}

int main() {
    scanf("%lld", &m);
    dfs(m, 0, 0);
    printf("%d %lld\n", ans.first, ans.second);
    return 0;
}