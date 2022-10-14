#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 100005;

llint n, root, cnt, sol;
int siz[MAXN], dub[MAXN], pos[MAXN];
vector <int> v[MAXN];
vector <pi> comp[MAXN];
priority_queue <pi> pq;

void dfs (int x, int rod) {
    siz[x] = 1;
    for (auto sus : v[x]) {
        if (sus == rod) continue;
        dfs(sus, x);
        siz[x] += siz[sus];
    }
    sol += 2 * min((llint) siz[x], n - siz[x]);
}

int nadi (int x, int rod) {
    int mx = 0, ind = -1;
    for (auto sus : v[x]) {
        if (sus == rod) continue;
        if (siz[sus] > mx) {
            mx = siz[sus];
            ind = sus;
        }
    }
    if (mx * 2 > n) return nadi(ind, x);
    return x;
}

void dfs2 (int x, int rod) {
    dub[x] = 1 + dub[rod];
    siz[x] = 1;
    comp[cnt].push_back({dub[x], x});
    for (auto sus : v[x]) {
        if (sus == rod) continue;
        dfs2(sus, x);
        siz[x] += siz[sus];
    }
}

void construct () {
    for (auto sus : v[root]) {
        cnt++;
        dfs2(sus, root);
        sort(comp[cnt].begin(), comp[cnt].end());
        pq.push({siz[sus], cnt});
    }
    while (pq.size() >= 2) {
        int a = pq.top().second, siza = pq.top().first; pq.pop();
        int b = pq.top().second, sizb = pq.top().first; pq.pop();
        int pa = comp[a].back().second, pb = comp[b].back().second;
        comp[a].pop_back(); comp[b].pop_back();
        if (pq.size() == 0 && siza == 1 && sizb == 1) {
            pos[pa] = pb;
            pos[pb] = root;
            pos[root] = pa;
            break;
        }
        pos[pa] = pb; pos[pb] = pa;
        if (siza > 1) pq.push({siza - 1, a});
        if (sizb > 1) pq.push({sizb - 1, b});
    }
    if (pq.size() == 1) {
        int a = pq.top().second;
        int pa = comp[a].back().second;
        pos[pa] = root;
        pos[root] = pa;
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1, 0);
    root = nadi(1, 0);
    construct();
    cout << sol << endl;
    for (int i = 1; i <= n; i++) cout << pos[i] << " ";
    return 0;
}