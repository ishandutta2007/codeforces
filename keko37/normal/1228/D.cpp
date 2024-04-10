#include<bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

int n, m, moze = 1;
vector < pair <int, int> > e;
vector <int> v[MAXN];
int col[MAXN];

bool check () {
    for (auto par : e) {
        int a = par.first, b = par.second;
        if (col[a] == col[b]) return 0;
    }
    long long cnt[3] = {0, 0, 0};
    for (int i=1; i<=n; i++) {
        cnt[col[i]]++;
    }
    if (cnt[0] == 0 || cnt[1] == 0 || cnt[2] == 0) return 0;
    return cnt[0] * cnt[1] + cnt[0] * cnt[2] + cnt[1] * cnt[2] == m;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
        e.push_back({a, b});
    }
    for (auto sus : v[1]) {
        col[sus] = 1;
    }
    if (v[1].empty()) {
        moze = 0;
    } else {
        int x = v[1][0];
        for (auto sus : v[x]) {
            if (col[sus] == 1) col[sus] = 2;
        }
        if (!check()) moze = 0;
    }
    if (!moze) {
        cout << -1;
        return 0;
    }
    for (int i=1; i<=n; i++) {
        cout << col[i] + 1 << " ";
    }
    return 0;
}