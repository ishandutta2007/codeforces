#include <bits/stdc++.h>

using namespace std;

const int INF = 1000000005;
const int N = 1000005;
const int M = N << 2;

bool vis[N];

int n, k, dfs_cnt, l, r, val;
int arr[N], idx[N], last[N];
int seg[M], lazy[M];

vector<int> g[N];

stack<int> st;

void DFS(int node) {
    idx[node] = last[node] = dfs_cnt++;
    vis[node] = true;
    for (int i = 0; i < (int)g[node].size(); i++) {
        DFS(g[node][i]);
        last[node] = last[g[node][i]];
    }
}

inline void fix(int s, int e, int idx) {
    seg[idx] += lazy[idx];
    if (s != e) {
        lazy[(idx << 1)] += lazy[idx];
        lazy[(idx << 1) + 1] += lazy[idx];
    }
    lazy[idx] = 0;
}

int update(int s, int e, int idx) {
    fix(s, e, idx);
    if (s > r || e < l) return seg[idx];
    if (s >= l && e <= r) {
        lazy[idx] += val;
        fix(s, e, idx);
        return seg[idx];
    }
    return seg[idx] = max(update(s, (s + e) / 2, idx * 2),
                          update((s + e) / 2 + 1, e, idx * 2 + 1));
}

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
        while ((int)st.size() > 0 && arr[i] > arr[st.top()]) {
            g[i].push_back(st.top());
            st.pop();
        }
        st.push(i);
    }
    for (int i = n - 1; i >= 0; --i) {
        if (!vis[i]) DFS(i);
    }
    int j = 0;
    for (j = 0; j < k; ++j) {
        l = idx[j];
        r = last[j];
        val = 1;
        update(0, n - 1, 1);
    }
    --j;
    int ss;
    while (j < n) {
        fix(0, n - 1, 1);
        printf("%d ", seg[1]);
        ss = j - k + 1;
        l = idx[ss];
        r = idx[ss];
        val = -INF;
        update(0, n - 1, 1);
        j++;
        if (j == n) break;
        l = idx[j];
        r = last[j];
        val = 1;
        update(0, n - 1, 1);
    }
    puts("");
    return 0;
}