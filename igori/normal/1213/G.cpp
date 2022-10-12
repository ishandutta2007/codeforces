#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <string>

using namespace std;

int n, m;

struct ed{
    int v, u;
    int c;
};

vector<ed> edges;
int root[500000];
long long sz[500000];

long long cur = 0;
long long ans[500000];

int Root(int x)
{
    if (root[x] == x) return x;
    return root[x] = Root(root[x]);
}

void Merge(int a, int b)
{
    if (sz[a] <= sz[b])
    {
        sz[b] += sz[a];
        root[a] = b;
    }
    else
    {
        sz[a] += sz[b];
        root[b] = a;
    }
}

int main()
{
    srand(time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) root[i] = i;
    for (int i = 1; i <= n; i++) sz[i] = 1;
    for (int i = 0; i < n - 1; i++)
    {
        int v, u, c;
        cin >> v >> u >> c;
        edges.push_back({v, u, c});
    }
    sort(edges.begin(), edges.end(), [&](ed a, ed b){
        return a.c < b.c;
    });
    for (int i = 0; i < n - 1; i++)
    {
        //cout << 1 << endl;
        int R1 = Root(edges[i].v);
        int R2 = Root(edges[i].u);
        //cout << R1 << " " << R2 << endl;
        //cout << 2 << endl;
        //cur -= sz[R1] * (sz[R1 - 1]) / 2;
        //cur -= sz[R2] * (sz[R2 - 1]) / 2;
        //cur += (sz[R1] + sz[R2]) * (sz[R1] + sz[R2] - 1) / 2;
        cur += sz[R1] * sz[R2];
        //cout << sz[R1] << " " << sz[R2] << endl;
        Merge(R1, R2);
        //cout << 3 << endl;
        ans[i + 1] = cur;
    }
    for (int i = 0; i < m; i++)
    {
        int q;
        cin >> q;
        int l = -1, r = n - 1;
        while (l + 1 < r)
        {
            int mid = (l + r) / 2;
            if (edges[mid].c <= q)
            {
                l = mid;
            }
            else
            {
                r = mid;
            }
        }
        cout << ans[l + 1] << " ";
    }
}