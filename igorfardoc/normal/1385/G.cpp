#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
vector<vector<pair<int, int>>> g;
vi c;
bool ok;
vi fir, sec;

void dfs(int v) {
    for(auto& el : g[v]) {
        int u = el.first;
        int t = el.second;
        if(c[u] == 2) {
            if(t == 0) {
                c[u] = c[v];
            } else {
                c[u] = 1 - c[v];
            }
            if(c[u] == 0) {
                fir.push_back(u);
            } else {
                sec.push_back(u);
            }
            dfs(u);
        } else {
            if((c[u] == c[v] && t == 1) || (c[u] != c[v] && t == 0)) {
                ok = false;
            }
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
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vi a(n), b(n);
        vvi am(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            --a[i];
            am[a[i]].push_back(i);
        }
        for(int i = 0; i < n; i++) {
            cin >> b[i];
            --b[i];
            am[b[i]].push_back(i);
        }
        ok = true;
        for(int i = 0; i < n; i++) {
            if(am[i].size() != 2) {
                ok = false;
                break;
            }
        }
        if(!ok) {
            cout << -1 << '\n';
            continue;
        }
        g.assign(n, vector<pair<int, int>>(0));
        for(int i = 0; i < n; i++) {
            if(am[i][0] == am[i][1]) {
                continue;
            }
            if((a[am[i][0]] == i && a[am[i][1]] == i) || (b[am[i][0]] == i && b[am[i][1]] == i)) {
                g[am[i][0]].push_back({am[i][1], 1});
                g[am[i][1]].push_back({am[i][0], 1});
                //cout << "Other " << am[i][0] << ' ' << am[i][1] << endl;
            } else {
                g[am[i][0]].push_back({am[i][1], 0});
                g[am[i][1]].push_back({am[i][0], 0});
                //cout << "Eq " << am[i][0] << ' ' << am[i][1] << endl;
            }
        }
        c.assign(n, 2);
        vi ans;
        for(int i = 0; i < n; i++) {
            if(c[i] == 2) {
                fir.clear();
                sec.clear();
                c[i] = 0;
                fir.push_back(i);
                dfs(i);
                if(!ok) {
                    break;
                }
                if(fir.size() < sec.size()) {
                    for(auto el : fir) {
                        ans.push_back(el);
                    }
                } else {
                    for(auto el : sec) {
                        ans.push_back(el);
                    }
                }
            }
        }
        if(!ok) {
            cout << -1 << '\n';
            continue;
        }
        cout << ans.size() << '\n';
        for(int i = 0; i < ans.size(); i++) {
            cout << ans[i] + 1 << ' ';
        }
        cout << '\n';
    }

}