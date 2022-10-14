#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 300005;

llint n, sol, cnt;
int p[MAXN], par[MAXN], lo[MAXN], hi[MAXN], dub[MAXN];
int pre[MAXN], post[MAXN], ord[MAXN], bio[MAXN];
vector <int> v[MAXN];
vector <pi> r;

int get_mn_child (int x) {
    int mn = 1e9, ind = -1;
    for (auto sus : v[x]) {
        if (p[x] < p[sus] && p[sus] < mn) {
            mn = p[sus];
            ind = sus;
        }
    }
    return ind;
}

bool init () {
    sort(r.begin(), r.end());
    int curr = -1;
    for (auto pp : r) {
        int i = pp.second;
        if (get_mn_child(i) == -1) {
            bio[i] = 1;
            continue;
        }
        curr = i;
        break;
    }
    if (curr == -1) return 1;
    while (curr != 1) {
        int nxt = par[curr];
        swap(p[curr], p[nxt]);
        if (get_mn_child(nxt) != curr) return 0;
        curr = nxt;
        sol++;
    }
    return 1;
}

bool cmp (int i, int j) {
    return lo[i] < lo[j];
}

void calc (int x) {
    lo[x] = hi[x] = p[x];
    dub[x] = 1 + dub[par[x]];
    for (auto sus : v[x]) {
        calc(sus);
        lo[x] = min(lo[x], lo[sus]);
        hi[x] = max(hi[x], hi[sus]);
    }
    sort(v[x].begin(), v[x].end(), cmp);
}

void dfs (int x) {
    ord[x] = ++cnt;
    for (auto sus : v[x]) dfs(sus);
}

void dfs_pre (int x) {
    if (bio[x]) return;
    cnt++;
    pre[x] = cnt;
    for (auto sus : v[x]) {
        dfs_pre(sus);
    }
}

void dfs_post (int x) {
    for (auto sus : v[x]) {
        dfs_post(sus);
    }
    cnt++;
    post[x] = cnt;
}

bool check () {
    calc(1);
    dfs_post(1);
    cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (bio[i] == 1) {
            cnt++;
            if (p[i] != post[i]) return 0;
            sol += dub[i] - 1;
        }
    }
    dfs_pre(1);
    for (int i = 1; i <= n; i++) {
        if (bio[i] == 0) {
            if (p[i] != pre[i]) return 0;
        }
    }
    return 1;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        r.push_back({p[i], i});
    }
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        par[b] = a;
        v[a].push_back(b);
    }
    if (init() == 0 || check() == 0) {
        cout << "NO";
    } else {
        cout << "YES\n";
        cout << sol << '\n';
        cnt = 0;
        dfs(1);
        for (int i = 1; i <= n; i++) cout << ord[i] << " ";
    }
    return 0;
}