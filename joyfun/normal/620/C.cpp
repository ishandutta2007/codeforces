#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

const int N = 300005;

int n, a[N];
map<int, int> cnt;
vector<pair<int, int> > ans;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d",&a[i]);
    int pre = 1;
    for (int i = 1; i <= n; i++) {
        cnt[a[i]]++;
        if (cnt[a[i]] == 2) {
            ans.push_back(make_pair(pre, i));
            while (pre <= i) {
                cnt[a[pre++]]--;
            }
        }
    }
    int sz = ans.size();
    if (sz == 0) printf("-1\n");
    else {
        ans[sz - 1].second = n;
        printf("%d\n", sz);
        for (int i = 0; i < sz; i++)
            printf("%d %d\n", ans[i].first, ans[i].second);
    }
    return 0;
}