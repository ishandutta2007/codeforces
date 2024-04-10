#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
vector<int> tree[N];
int sz[N];
bool used[N];
char ans[N];

int getSize(int i, int p) {
    sz[i] = 1;
    for(int j : tree[i])
        if(j != p && !used[j])
            sz[i] += getSize(j, i);
    return sz[i];
}

int centroid(int i, int p, int n) {
    for(int j : tree[i])
        if(j != p && !used[j] && sz[j] > n / 2)
            return centroid(j, i, n);
    return i;
}

void decomp(int i, char rank) {
    int cent = centroid(i, -1, getSize(i, -1));
    ans[cent] = rank;
    used[cent] = true;
    for(int j : tree[cent])
        if(!used[j])
            decomp(j, rank + 1);
}

int main() {
    int n, u, v;
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    decomp(1, 'A');
    for(int i = 1; i <= n; i++)
        cout << ans[i] << " ";
}