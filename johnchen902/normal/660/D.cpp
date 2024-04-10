#include <cstdio>
#include <algorithm>
#include <utility>
using namespace std;
pair<int, int> p[2000];
pair<int, int> mp[(2000 * 1999) / 2];
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d %d", &p[i].first, &p[i].second);
    int m = 0;
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
            mp[m].first = p[i].first + p[j].first,
            mp[m++].second = p[i].second + p[j].second;
    sort(mp, mp + m);
    unsigned long long ans = 0;
    for(int i = 0; i < m;) {
        int j = i + 1;
        while(j < m && mp[i] == mp[j])
            j++;
        ans += (unsigned long long) (j - i) * (j - i - 1) / 2;
        i = j;
    }
    printf("%llu\n", ans);
}