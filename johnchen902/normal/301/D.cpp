#pragma GCC optimize "-O3"
#include <cstdio>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;

static int rev[200001];
static int p[200000];

static int bit[1 << 18];
static int ans[200000];
static vector<tuple<int, int, int>> vec[200001];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        scanf("%d", p + i);
        rev[p[i]] = i;
    }

    for (int i = 0; i < m; i++) {
        int l, r;
        scanf("%d %d", &l, &r);
        l--;
        vec[r].emplace_back(r, i, +1);
        vec[r].emplace_back(l, i, -1);
        vec[l].emplace_back(r, i, -1);
        vec[l].emplace_back(l, i, +1);
    }

    for (int i = 0; i < n;) {
        for (int j = p[i]; j <= n; j += p[i])
            for (int x = rev[j] + 1; x <= 1 << 18; x += x & -x)
                bit[x - 1]++;
        i++;
        for (auto t : vec[i]){
            int v = 0;
            for (int x = get<0>(t); x; x -= x & -x)
                v += bit[x - 1];
            ans[get<1>(t)] += v * get<2>(t);
        }
    }

    for (int i = 0; i < m; i++)
        printf("%d\n", ans[i]);
}