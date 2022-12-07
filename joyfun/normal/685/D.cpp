#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 100005;
int n, k;
vector<int> h;
vector<pair<int, int> > x;
int xx[N], yy[N], cnt[N * 2], pre[N * 2];
long long ans[N];

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &xx[i], &yy[i]);
        h.push_back(yy[i]); h.push_back(yy[i] + k);
        x.push_back(make_pair(xx[i], i<<1));
        x.push_back(make_pair(xx[i] + k, (i<<1)|1));
    }
    sort(h.begin(), h.end());
    h.erase(unique(h.begin(), h.end()), h.end());
    sort(x.begin(), x.end());
    for (int i = 0; i < x.size(); i++) {
        int id = x[i].second>>1;
        int f = x[i].second&1 ? -1 : 1;
        for (int j = lower_bound(h.begin(), h.end(), yy[id]) - h.begin(); h[j] < yy[id] + k; j++) {
            if (cnt[j]) ans[cnt[j]] += 1LL * (h[j + 1] - h[j]) * (x[i].first - pre[j]);
            cnt[j] += f;
            pre[j] = x[i].first;
        }
    }
    for (int i = 1; i <= n; i++) printf("%lld ", ans[i]); printf("\n");
    return 0;
}