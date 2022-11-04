#include<bits/stdc++.h>
#define maxn 1000
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
multiset<int> b[maxn][maxn];
int n, m;
queue<pair<int, int>> q;
bool used[maxn][maxn];
int a[maxn][maxn];

void add(int i, int j, int val) {
    for(int dx = -1; dx <= 0; dx++) {
        for(int dy = -1; dy <= 0; dy++) {
            int x = i + dx;
            int y = j + dy;
            if(x < 0 || y < 0 || x >= n - 1 || y >= m - 1) continue;
            b[x][y].insert(val);
        }
    }
}

void try_add(int i, int j) {
    if(used[i][j]) return;
    int val = -1;
    for(const auto& el : b[i][j]) {
        if(el == -1) continue;
        if(val == -1) val = el;
        if(val != el) return;
    }
    q.push({i, j});
    used[i][j] = true;
}

int get_col(int i, int j) {
    for(const auto& el : b[i][j]) {
        if(el != -1) return el;
    }
    return -1;
}

void rebuild(int i, int j) {
    if(used[i][j]) return;
    b[i][j].clear();
    for(int dx = 0; dx <= 1; dx++) {
        for(int dy = 0; dy <= 1; dy++) {
            b[i][j].insert(a[i + dx][j + dy]);
        }
    }
    try_add(i, j);
}

void free(int i, int j) {
    for(int dx = 0; dx <= 1; dx++) {
        for(int dy = 0; dy <= 1; dy++) {
            a[dx + i][dy + j] = -1;
        }
    }
    for(int dx = -1; dx <= 1; dx++) {
        for(int dy = -1; dy <= 1; dy++) {
            if(dx == 0 && dy == 0) continue;
            int x = dx + i;
            int y = dy + j;
            if(x < 0 || y < 0 || x >= n - 1 || y >= m - 1) continue;
            rebuild(x, y);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            add(i, j, a[i][j]);
        }
    }
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < m - 1; j++) {
            try_add(i, j);
        }
    }
    vector<array<int, 3>> ans;
    while(!q.empty()) {
        auto p = q.front();
        q.pop();
        int x = p.first;
        int y = p.second;
        int col = get_col(x, y);
        if(col != -1) {
            ans.push_back({x, y, col});
        }
        free(x, y);
    }
    bool ok = true;
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < m - 1; j++) {
            if(!used[i][j]) ok = false;
        }
    }
    if(!ok) {
        cout << -1;
        return 0;
    }
    cout << ans.size() << '\n';
    reverse(ans.begin(), ans.end());
    for(const auto& el : ans) {
        cout << el[0] + 1 << ' ' << el[1] + 1 << ' ' << el[2] << '\n';
    }
}