#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

map<int, int> x, y;
map<pair<int, int>, int> s;

int main() {
    int n, a, b;
    scanf("%d", &n);
    long long ans = 0;
    while (n--) {
        scanf("%d%d", &a, &b);
        x[a]++; y[b]++;
        s[make_pair(a, b)]++;
    }
    for (map<int, int>::iterator it = x.begin(); it != x.end(); it++) {
        int tmp = it->second;
        ans += 1LL * tmp * (tmp - 1) / 2;
    }
    for (map<int, int>::iterator it = y.begin(); it != y.end(); it++) {
        int tmp = it->second;
        ans += 1LL * tmp * (tmp - 1) / 2;
    }
    for (map<pair<int, int> , int>::iterator it = s.begin(); it != s.end(); it++) {
        int tmp = it->second;
        ans -= 1LL * tmp * (tmp - 1) / 2;
    }
    printf("%lld\n", ans);
    return 0;
}