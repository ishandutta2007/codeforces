#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
const int MOD = 998244353;

typedef pair<int, int> ii;
#define X first
#define Y second
int n, m, k;
int e[N][3];
vector<int> imp[N];
int ans[N][2];
    
int pe[N];
int a[N];
ii tr[N];
ii operator +(ii a, ii b) {
    return ii(a.X + b.X, a.Y + b.Y);
}
int root(int x) {
    if (tr[x].X < 0) return x;
    return tr[x].X = root(tr[x].X);
}
void merge(int x, int y) {
    int rx = root(x), ry = root(y);
    if (rx == ry) return;
    if (tr[rx].X < tr[ry].X) swap(rx, ry);
    tr[ry] = tr[ry] + tr[rx];
    tr[rx] = ii(ry, 0);
}

void check() {
    for(int i = 1; i <= n; i++) tr[i] = ii(-1, 0);
    for(int i = 1; i <= k; i++) tr[a[i]].Y++;


    for(int i = 1; i <= m; i++) {
        int use = pe[i];
        merge(e[use][0], e[use][1]);

        for(auto x : imp[i]) {
            int rx = root(a[x]);
            if (tr[rx].Y != k) ans[x][0] = i + 1;
            else ans[x][1] = i - 1;
        }
        imp[i].clear();
    }
}
int main() {
    cin >> n >> m >> k;
    for(int i = 1; i <= k; i++) cin >> a[i];
    for(int i = 1; i <= m; i++) {
        for(int j = 0; j < 3; j++) cin >> e[i][j];
    }
    for(int i = 1; i <= m; i++) pe[i] = i;
    sort(pe + 1, pe + m + 1, [](int x, int y) {
        return e[x][2] < e[y][2];
    });


    for(int i = 1; i <= n; i++) {
        ans[i][0] = 1, ans[i][1] = m; 
    }


    for(int j = 1; j <= 20; j++) {
        for(int i = 1; i <= k; i++) if (ans[i][0] <= ans[i][1]){
            int mid = (ans[i][0] + ans[i][1]) / 2;
            imp[mid].push_back(i);
        }
        check();
    }
    for(int i = 1; i <= k; i++) cout << e[pe[ans[i][0]]][2] << " " ;
}