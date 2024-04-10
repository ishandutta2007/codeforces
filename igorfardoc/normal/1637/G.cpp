#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
int n;
vector<pair<int, int>> ans;
map<int, int> am;


void solve(int n, int mult) {
    if(n <= 0) {
        return;
    }
    int now = 1;
    while(now * 2 <= n) {
        now *= 2;
    }
    if(now == n) {
        ++am[now * mult];
        return solve(n - 1, mult);
    }
    int mx = 0;
    for(int dt = 1; now + dt <= n; dt++) {
        ans.push_back({(now + dt) * mult, (now - dt) * mult});
        ++am[2 * now * mult];
        mx = dt;
    }
    ++am[now * mult];
    solve(now - mx - 1, mult);
    solve(mx, mult * 2);
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
        cin >> n;
        ans.clear();
        am.clear();
        if(n == 2) {
            cout << -1 << '\n';
            continue;
        }
        int p = 1;
        while(p < n) {
            p *= 2;
        }
        solve(n, 1);
        for(auto it = am.begin(); it != am.end(); ++it) {
            if(it->second > 1) {
                ans.push_back({it->first, it->first});
                int id = it->first;
                am[id] -= 2;
                ++am[id * 2];
                break;
            }
        }
        while(am.begin()->first != p) {
            int id = am.begin()->first;
            int amount = am.begin()->second;
            am.erase(am.begin());
            am[id * 2] += amount;
            for(int i = 0; i < amount; i++) {
                ans.push_back({0, id});
                ans.push_back({id, id});
            }
        }
        ans.push_back({p, 0});
        cout << ans.size() << '\n';
        for(const auto& el : ans) {
            cout << el.first << ' ' << el.second << '\n';
        }
    }


}