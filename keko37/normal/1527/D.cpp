#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 200005;

int t, n, cx, cy, cnt, root;
int siz[MAXN], par[MAXN], bio[MAXN];
llint sol[MAXN];
vector <int> v[MAXN];

void dfs (int x, int rod) {
    par[x] = rod;
    siz[x] = 1;
    for (auto sus : v[x]) {
        if (sus == rod) continue;
        dfs(sus, x);
        siz[x] += siz[sus];
    }
}

bool upd (int node) {
    if (bio[node] == 1) return 1;
    int curr = node;
    while (bio[curr] == 0) {
        bio[curr] = 1;
        cnt++;
        curr = par[curr];
    }
    if (curr != cx && curr != cy) return 0;
    if (curr == cx) cx = node; else cy = node;
    return 1;
}

llint calc () {
    llint res = 0;
    if (cnt == 1) {
        dfs(cx, -1);
        res += (llint) n * (n - 1) / 2;
        for (auto sus : v[cx]) {
            res -= (llint) siz[sus] * (siz[sus] - 1) / 2;
        }
    } else if (cnt == 2) {
        dfs(cx, -1);
        res = (llint) (n - siz[cy]) * siz[cy];
    } else {
        if (root == -1) {
            for (int i = 0; i < n; i++) {
                if (bio[i] == 1 && i != cx && i != cy) {
                    root = i;
                    break;
                }
            }
            dfs(root, -1);
        }
        res = (llint) siz[cx] * siz[cy];
    }
    return res;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        cnt = 0; root = -1;
        cx = cy = 0;
        for (int i = 0; i <= n; i++) {
            v[i].clear();
            bio[i] = sol[i] = par[i] = siz[i] = 0;
        }
        for (int i = 0; i < n-1; i++) {
            int a, b;
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }

        cx = 0; cy = 0; cnt = 1;
        bio[0] = 1;

        sol[0] = calc(); sol[n] = 0;
        for (int i = 1; i < n; i++) {
            if (upd(i) == 0) break;
            sol[i] = calc();
        }
        cout << (llint) n * (n - 1) / 2 - sol[0] << " ";
        for (int i = 1; i <= n; i++) {
            cout << sol[i - 1] - sol[i] << " ";
        }
        cout << '\n';
    }
    return 0;
}