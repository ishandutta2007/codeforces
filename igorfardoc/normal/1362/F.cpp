#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
vector<vector<pair<int, int>>> g;
vector<vector<bool>> used;
vvi other;
vi ans;

void dfs(int v) {
    while(true) {
        while(!g[v].empty() && used[v][g[v].size() - 1]) {
            g[v].pop_back();
        }
        if(g[v].empty()) {
            break;
        }
        int i = g[v].size() - 1;
        int u = g[v][i].first;
        //cout << v << ' ' << u << endl;
        int ans1 = g[v][i].second;
        g[v].pop_back();
        used[u][other[v][i]] = true;
        dfs(u);
        ans.push_back(ans1);
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
    int n;
    cin >> n;
    vi a(n);
    vi b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    for(int i = 20; i >= 1; i--) {
        g.assign(1 << i, vector<pair<int, int>>(0));
        used.assign(1 << i, vector<bool>(0));
        other.assign(1 << i, vector<int>(0));
        for(int j = 0; j < n; j++) {
            int a1 = a[j] & ((1 << i) - 1);
            int b1 = b[j] & ((1 << i) - 1);
            g[a1].push_back({b1, 2 * j});
            used[a1].push_back(false);
            g[b1].push_back({a1, 2 * j + 1});
            used[b1].push_back(false);
            if(a1 != b1) {
                other[a1].push_back(g[b1].size() - 1);
                other[b1].push_back(g[a1].size() - 1);
            } else {
                other[a1].push_back(g[b1].size() - 1);
                other[b1].push_back(g[a1].size() - 2);
            }
            //cout << a1 << ' ' << b1 << endl;
        }
        //cout << endl;
        bool ok = true;
        int start = -1;
        for(int j = 0; j < (1 << i); j++) {
            if(g[j].size() % 2 == 1) {
                ok = false;
                break;
            }
            if(g[j].size() > 0) {
                start = j;
            }
        }
        if(!ok) {
            continue;
        }
        ans.clear();
        dfs(start);
        if(ans.size() != n) {
            continue;
        }
        reverse(ans.begin(), ans.end());
        cout << i << '\n';
        for(int j = 0; j < n; j++) {
            cout << ans[j] + 1 << ' ';
            if(ans[j] % 2 == 0) {
                cout << ans[j] + 2 << ' ';
            } else {
                cout << ans[j] << ' ';
            }
        }
        return 0;
    }



    cout << 0 << '\n';
    for(int i = 0; i < 2 * n; i++) {
        cout << i + 1 << ' ';
    }
}