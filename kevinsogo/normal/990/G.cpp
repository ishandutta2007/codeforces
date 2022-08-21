#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 200111;
vector<int> divs[N];
void init() {
    for (int i = 1; i < N; i++) {
        for (int j = i; j < N; j += i) {
            divs[j].push_back(i);
        }
    }
}

vector<pair<int,int>> edges[N];
int parent[N];
int size[N];
int vist[N];
int loc;
int find(int i) {
    if (vist[i] != loc) {
        vist[i] = loc;
        parent[i] = -1;
        size[i] = 1;
    }
    return parent[i] < 0 ? i : parent[i] = find(parent[i]);
}

int a[N];
ll ans[N];
int main() {
    init();
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i < n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        x--, y--;
        edges[__gcd(a[x], a[y])].emplace_back(x, y);
    }

    for (int v = N - 1; v >= 1; v--) {
        loc++;
        ll got = 0;
        for (int i = v; i < N; i += v) {
            for (auto& ed: edges[i]) {
                int a, b;
                tie(a, b) = ed;
                a = find(a);
                b = find(b);
                // printf("[%d] [%d] (%d %d) (%d %d)\n", v, i, ed.first, ed.second, a, b);
                assert(a != b);
                got += (ll) size[a] * size[b];
                if (parent[a] == parent[b]) parent[b]--;
                if (parent[a] > parent[b]) {
                    parent[a] = b;
                    size[b] += size[a];
                } else {
                    parent[b] = a;
                    size[a] += size[b];
                }
            }
            if (i > v) got -= ans[i];
        }
        ans[v] += got;
    }

    for (int i = 0; i < n; i++) {
        ans[a[i]]++;
    }

    for (int i = 1; i <= 200000; i++) {
        if (ans[i]) printf("%d %lld\n", i, ans[i]);
    }
}