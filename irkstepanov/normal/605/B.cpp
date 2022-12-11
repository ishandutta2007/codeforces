#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define sz(a) (int) (a).size()
#define all(a) (a).begin(), (a).end()

using namespace std;

typedef pair<int, int> pii;

struct edge
{
    int len;
    char taken;
    int id;
    bool operator<(const edge& other)
    {
        if (len != other.len) {
            return (len < other.len);
        }
        if (taken != other.taken) {
            return (taken);
        }
        return (id < other.id);
    }
};

int main()
{

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m;
    scanf("%d%d", &n, &m);

    vector<edge> edges(m);
    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        edges[i].len = a;
        edges[i].taken = (b ? true : false);
        edges[i].id = i;
    }

    sort(all(edges));

    vector<int> ptr(n);
    vector<pii> ans(m);
    int v = 0, k = 2;

    if (!edges[0].taken) {
        printf("-1\n");
        return 0;
    }

    ans[edges[0].id] = mp(0, 1);
    ptr[0] = 2;
    ptr[1] = 3;
    for (int i = 1; i < m; ++i) {
        if (edges[i].taken) {
            ans[edges[i].id] = mp(k - 1, k);
            ptr[k] = k + 2;
            ++k;
            v = 0;
            continue;
        }
        while (v < k && ptr[v] >= k) {
            ++v;
        }
        if (v == k) {
            printf("-1\n");
            return 0;
        }
        ans[edges[i].id] = mp(v, ptr[v]);
        ++ptr[v];
    }

    for (int i = 0; i < m; ++i) {
        printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
    }

}