#include<bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

int n, k, cnt;
vector <int> v[MAXN];
int bio[MAXN];

void dfs (int x) {
    if (bio[x]) return;
    bio[x] = 1;
    for (auto sus : v[x]) dfs(sus);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for (int i=0; i<k; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for (int i=1; i<=n; i++) {
        if (bio[i] == 0) {
            dfs(i);
            cnt++;
        }
    }
    cout << k - n + cnt;
    return 0;
}