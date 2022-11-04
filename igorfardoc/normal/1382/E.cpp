#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;



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
        int n, x, y;
        cin >> n >> x >> y;
        set<int> cols;
        vvi pos(n + 1);
        for(int i = 0; i <= n; i++) {
            cols.insert(i);
        }
        for(int i = 0; i < n; i++) {
            int a;
            cin >> a;
            --a;
            pos[a].push_back(i);
            auto it = cols.find(a);
            if(it != cols.end()) {
                cols.erase(it);
            }
        }
        vi ans(n, -10);
        set<pair<int, int>> s;
        for(int i = 0; i <= n; i++) {
            s.insert({pos[i].size(), i});
        }
        for(int i = 0; i < x; i++) {
            auto it = --s.end();
            auto p = *it;
            s.erase(it);
            int col = p.second;
            ans[pos[col][pos[col].size() - 1]] = col;
            pos[col].pop_back();
            s.insert({pos[col].size(), col});
        }
        y -= x;
        int now = n - x;
        int free = *(cols.begin());
        /*if(y == 1) {
            if(x == n - 1) {
                cout << "NO\n";
                continue;
            }
            set<int> colors;
            vector<pair<int, int>> p;
            for(int i = 0; i <= n; i++) {
                for(int pos1 : pos[i]) {
                    p.push_back({i, pos1});
                    colors.insert(i);
                }
            }
            if(colors.size() == 1) {
                cout << "NO\n";
                continue;
            }
            colors.erase(colors.find(p[0].first));
            ans[p[0].second] = *(colors.begin());
            for(int i = 1; i < p.size(); i++) {
                ans[p[i].second] = free;
            }
            cout << "YES\n";
            for(int el : ans) {
                cout << el + 1 << ' ';
            }
            cout << '\n';
            continue;
        }*/
        bool ok = true;
        int big = -1;
        vector<pair<int, int>> p;
        for(int i = 0; i <= n; i++) {
            if(pos[i].size() * 2 > n - x && (n - x - pos[i].size()) * 2 < y) {
                ok = false;
                break;
            }
            if(pos[i].size() * 2 > n - x) {
                big = i;
            }
            for(int pos1 : pos[i]) {
                p.push_back({i, pos1});
            }
        }
        if(!ok) {
            cout << "NO\n";
            continue;
        }
        if(big == -1) {
            for(int i = 0; i < p.size(); i++) {
                if(i < y) {
                    ans[p[i].second] = p[(i + p.size() / 2) % p.size()].first;
                } else {
                    ans[p[i].second] = free;
                }
            }
        } else {
            int now3 = 0;
            while(pos[big].size() * 2 > n - x - now3) {
                ++now3;
                ans[pos[big][pos[big].size() - 1]] = free;
                pos[big].pop_back();
            }
            p.clear();
            for(int pos1 : pos[big]) {
                p.push_back({big, pos1});
            }
            for(int i = 0; i <= n; i++) {
                if(i == big) continue;
                for(int pos1 : pos[i]) {
                    p.push_back({i, pos1});
                }
            }
            for(int i = 0; i < p.size(); i++) {
                if(i < y) {
                    ans[p[i].second] = p[(i + (p.size() - 1) / 2 + 1) % p.size()].first;
                } else {
                    ans[p[i].second] = free;
                }
            }
        }
        cout << "YES\n";
        for(int i = 0; i < n; i++) {
            cout << ans[i] + 1 << ' ';
        }
        cout << '\n';
    }
}