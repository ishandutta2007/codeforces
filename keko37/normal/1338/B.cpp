#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 100005;

int n;
vector <int> v[MAXN];
int bio[MAXN], col[MAXN];

void dfs (int x, int rod, bool flg) {
    col[x] = flg;
    for (auto sus : v[x]) {
        if (sus == rod) continue;
        dfs(sus, x, !flg);
    }
}

void calc_min () {
    dfs(1, 0, 0);
    int cnt[2] = {0, 0};
    for (int i = 1; i <= n; i++) {
        if (v[i].size() == 1) cnt[col[i]]++;
    }
    if (cnt[0] > 0 && cnt[1] > 0) cout << 3 << " "; else cout << 1 << " ";
}

void calc_max () {
    int res = 0;
    for (int i = 1; i <= n; i++) {
        if (v[i].size() == 1) {
            int par = v[i][0];
            bio[par] = 1;
        } else {
            for (auto sus : v[i]) {
                if (i < sus && v[sus].size() > 1) res++;
            }
        }
    }
    for (int i = 1; i <= n; i++) res += bio[i];
    cout << res;
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
    calc_min();
    calc_max();
    return 0;
}