#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    int m;
    cin >> m;
    vector<map<int, int>> nums(m);
    vector<vector<bool>> ans(m);
    unordered_map<int, set<int>> numCt;
    for(int i = 0; i < m; i++) {
        map<int, int> s;
        int n;
        cin >> n;
        ans[i].resize(n);
        for(int j = 0; j < n; j++) {
            int x;
            cin >> x;
            if(s.count(x)) {
                ans[i][j] = true;
                s.erase(x);
            }
            else s[x] = j;
        }
        for(auto g : s) {
            nums[i][g.first] = g.second;
            numCt[g.first].insert(i);
        }
    }
    bool ok = true;
    for(auto p : numCt) {
        if(p.second.size()%2) ok = false;
    }
    if(!ok) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES" << endl;
    auto applyNext = [&](int g) {
        int h = *(numCt[g].begin());
        assert(nums[h].size() > 0);
        numCt[g].erase(h);
        nums[h].erase(g);
        if(numCt[g].size() == 0) numCt.erase(g);
        auto p = *(nums[h].begin());
        ans[h][p.second] = true;
        int ret = p.first;
        nums[h].erase(p.first);
        numCt[p.first].erase(h);
        if(numCt[p.first].size() == 0) numCt.erase(p.first);
        return ret;
    };
    while(numCt.size()) {
        int g = (*(numCt.begin())).first;
        int h = applyNext(g);
        while(g != h) {
            h = applyNext(h);
        }
    }
    for(auto v : ans) {
        for(bool b : v) {
            cout << (b ? "L" : "R");
        }
        cout << '\n';
    }
}