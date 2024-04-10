#include <bits/stdc++.h>

using namespace std;

const int N = 2E5 + 7;

map<int, int> mp;
int cnt[N], vis[N], a[N];
int BLOCK;
int ans[N];
int num[N], tot;
int n, q;
int cntq;
int cntc;

struct QQ {
    int l, r, z, id;
} Q[N];
struct CC {
    int x, y;
} C[N];
bool cmp(QQ a, QQ b) {
    if (a.l / BLOCK == b.l / BLOCK) {
        if (a.r / BLOCK == b.r / BLOCK) return a.z < b.z;
        return a.r < b.r;
    } else {
        return a.l < b.l;
    }
}

void add(int x) {
    --vis[cnt[num[x]]];
    ++cnt[num[x]];
    ++vis[cnt[num[x]]];
}
void dec(int x) {
    --vis[cnt[num[x]]];
    --cnt[num[x]];
    ++vis[cnt[num[x]]];
}

void solve() {
    int l = 1, r = 1, c = 0, res;
    add(1);
    for (int i = 1; i <= cntq; ++i) {
        while (r < Q[i].r) add(++r);
        while (r > Q[i].r) dec(r--);
        while (l < Q[i].l) dec(l++);
        while (l > Q[i].l) add(--l);

        while (c > Q[i].z) {
            if (C[c].x >= l && C[c].x <= r) dec(C[c].x);
            swap(C[c].y, num[C[c].x]);
            if (C[c].x >= l && C[c].x <= r) add(C[c].x);
            c--;
        }
        while (c < Q[i].z) {
            c++;
            if (C[c].x >= l && C[c].x <= r) dec(C[c].x);
            swap(C[c].y, num[C[c].x]);
            if (C[c].x >= l && C[c].x <= r) add(C[c].x);
        }
        res = 1;
        while (vis[res]) ++res;
        ans[Q[i].id] = res;
    }
    for (int i = 1; i <= cntq; i++) printf("%d\n", ans[i]);
}

int main() {
    scanf("%d %d", &n, &q);
    BLOCK = (int)pow(n, 2.0 / 3.0);
    for (int i = 1; i <= n; ++i) {
        int x;
        scanf("%d", &x);
        if (mp[x])
            num[i] = mp[x];
        else
            num[i] = mp[x] = ++tot;
    }
    int opt, l, r;
    for (int i = 1; i <= q; ++i) {
        scanf("%d %d %d", &opt, &l, &r);
        if (opt == 1) {
            ++cntq;
            Q[cntq] = (QQ){l, r, cntc, cntq};
        } else {
            ++cntc;
            if (mp[r]){
                r = mp[r];}
            else{
                r = mp[r] = ++tot;}
            C[cntc] = (CC){l, r};
        }
    }
    sort(Q + 1, Q + 1 + cntq, cmp);
    solve();
    return 0;
}