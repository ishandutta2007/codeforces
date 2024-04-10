#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 200111;

ll s[N], flow[N], src[N];
vector<pair<int,int>> adj[N];
bool vis[N];

ll solve(int i) {
    vis[i] = true;
    ll mern = s[i];
    for (auto& nb: adj[i]) {
        int j = nb.first;
        if (vis[j]) continue;
        ll got = solve(j);
        mern += got;
        if (src[nb.second] == j) got = -got;
        flow[nb.second] += got;
    }
    return mern;
}
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%lld", &s[i]);
    int e;
    scanf("%d", &e);
    for (int i = 0; i < e; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        --a, --b;
        src[i] = a;
        adj[a].emplace_back(b, i);
        adj[b].emplace_back(a, i);
    }
    ll push = solve(0);
    if (push == 0) {
        printf("Possible\n");
        for (int i = 0; i < e; i++) {
            printf("%lld\n", flow[i]);
        }
    } else {
        printf("Impossible\n");
    }
}