#include <bits/stdc++.h>
using namespace std;

struct SCC {
    vector<pair<int, int>> minmax;
    int size;

    SCC(vector<int> v) {
        minmax.resize(v.size());
        for (int i = 0; i < (int)v.size(); i++) {
            minmax[i].first = v[i];
            minmax[i].second = v[i];
        }
        size = 1;
    }

    bool operator<(SCC const& other) const {
        for (int i = 0; i < (int)minmax.size(); i++) {
            if (other.minmax[i].first < minmax[i].second)
                return false;
        }
        return true;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    
    set<SCC> s;
    for (int i = 0; i < n; i++) {
        vector<int> v(k);
        for (int i = 0; i < k; i++) {
            cin >> v[i];
        }
        
        SCC scc(v);
        auto a = s.lower_bound(scc);
        auto b = s.upper_bound(scc);
        if (a != b) {
            auto x = a;
            while (x != b) {
                for (int K = 0; K < k; K++) {
                    scc.minmax[K].first = min(scc.minmax[K].first, x->minmax[K].first);
                    scc.minmax[K].second = max(scc.minmax[K].second, x->minmax[K].second);
                }
                scc.size += x->size;
                x++;
            }
            s.erase(a, b);
        }
        s.insert(scc);
        cout << s.rbegin()->size << '\n';
    }
}