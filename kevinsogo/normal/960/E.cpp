#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1'000'000'007;
const int N = 211111;

ll vs[N];
int parent[N];
vector<int> adj[N];
ll topc[N][2];
ll top[N][2];
ll botc[N];
ll bot[N];
ll tot[N];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &vs[i]);
        parent[i] = -1;
    }
    for (int i = 1; i < n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    parent[0] = 0;
    vector<int> stack, pre;
    stack.push_back(0);
    while (!stack.empty()) {
        int i = stack.back(); stack.pop_back();
        pre.push_back(i);
        for (int j : adj[i]) {
            if (parent[j] == -1) {
                parent[j] = i;
                stack.push_back(j);
            }
        }
    }
    reverse(pre.begin(), pre.end());
    for (int i : pre) {
        for (int j : adj[i]) {
            if (j == parent[i]) continue;

            top[i][0] += top[j][1];
            top[i][0] %= mod;
            top[i][1] += top[j][0];
            top[i][1] %= mod;

            bot[i] += bot[j];
            bot[i] %= mod;

            topc[i][0] += topc[j][1];
            topc[i][1] += topc[j][0];
            botc[i] += botc[j];

            tot[i] += tot[j];
            tot[i] %= mod;

            tot[i] -= top[j][0] * botc[j] % mod + vs[i] * botc[j] % mod * topc[j][0] - topc[j][0] * bot[j] % mod;
            tot[i] %= mod;
            tot[i] -= top[j][1] * botc[j] % mod - vs[i] * botc[j] % mod * topc[j][1] + topc[j][1] * bot[j] % mod;
            tot[i] %= mod;
        }

        tot[i] += top[i][1] * botc[i] % mod  + vs[i] * botc[i] % mod * topc[i][1] - topc[i][1] * bot[i] % mod;
        tot[i] %= mod;
        tot[i] += top[i][0] * botc[i] % mod  - vs[i] * botc[i] % mod * topc[i][0] + topc[i][0] * bot[i] % mod;
        tot[i] %= mod;

        // add curr
        topc[i][1]++;
        botc[i]++;
        bot[i] = vs[i] * botc[i] - bot[i] % mod;
        bot[i] %= mod;
        top[i][0] = top[i][0] % mod - vs[i] * topc[i][0];
        top[i][0] %= mod;
        top[i][1] = top[i][1] % mod + vs[i] * topc[i][1];
        top[i][1] %= mod;

        tot[i] += top[i][0];
        tot[i] += top[i][1];
        tot[i] += bot[i];
        tot[i] -= vs[i];
        tot[i] %= mod;

    }

    if ((tot[0] %= mod) < 0) tot[0] += mod;
    printf("%lld\n", tot[0]);
}