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
    int n, m;
    cin >> n >> m;
    vi w(n);
    for(int i = 0; i < n; i++) {
        cin >> w[i];
    }
    vi x(m), y(m);
    vector<set<int>> am(n);
    for(int i = 0; i < m; i++) {
        cin >> x[i] >> y[i];
        --x[i];
        --y[i];
        am[x[i]].insert(i);
        am[y[i]].insert(i);
    }
    set<pair<int, int>> s;
    for(int i = 0; i < n; i++) {
        s.insert({(int)am[i].size() - w[i], i});
    }
    vi ans;
    while(!s.empty()) {
        auto p = *(s.begin());
        s.erase(s.begin());
        if(p.first > 0) {
            cout << "DEAD\n";
            return 0;
        }
        for(const auto& el : am[p.second]) {
            ans.push_back(el);
            int id1 = x[el];
            if(x[el] == p.second) {
                id1 = y[el];
            }
            auto it = am[id1].find(el);
            if(it != am[id1].end()) {
                s.erase(s.find({am[id1].size() - w[id1], id1}));
                am[id1].erase(it);
                s.insert({am[id1].size() - w[id1], id1});
            }
        }
    }
    cout << "ALIVE\n";
    for(int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i] + 1 << ' ';
    }

}