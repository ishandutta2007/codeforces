#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 250005;

int n, m;
int val[MAXN], cnt[MAXN];
vector <int> v[MAXN];
unordered_map <int, int> mp;

int get (int col) {
    mp.clear();
    for (int i = 0; i < n; i++) {
        mp[v[i][col]]++;
    }
    pi best = {0, 0};
    for (auto pp : mp) {
        best = max(best, {pp.second, pp.first});
    }
    return best.second;
}

void upd (int col, int x) {
    for (int i = 0; i < n; i++) {
        if (val[col] != v[i][col]) cnt[i]--;
    }
    val[col] = x;
    for (int i = 0; i < n; i++) {
        if (val[col] != v[i][col]) cnt[i]++;
    }
}

bool f (int dub) {
    int row = -1;
    for (int i = 0; i < n; i++) {
        if (cnt[i] > 2) {
            row = i;
            break;
        }
    }
    if (row == -1) return 1;
    if (dub >= 4 || cnt[row] >= 5) return 0;
    for (int i = 0; i < m; i++) {
        if (v[row][i] != val[i]) {
            int was = val[i];
            upd(i, v[row][i]);
            if (f(dub + 1)) return 1;
            upd(i, was);
        }
    }
    return 0;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        v[i].resize(m);
        cnt[i] = m;
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        upd(i, get(i));
    }
    if (f(0)) {
        cout << "Yes\n";
        for (int i = 0; i < m; i++) cout << val[i] << " ";
    } else {
        cout << "No\n";
    }
    return 0;
}