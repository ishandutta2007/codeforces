#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    vector<int> v(n);
    for (int idx = 0; idx < n; idx++)
        cin >> v[idx];
    
    // vector<vector<int>> bits(22);
    // for (int i = 0; i < n; i++) {
    //     int num = v[i];
    //     for (int j = 0; j < 22; j++) {
    //         if (num & 1) bits[j].push_back(i);
    //         num >>= 1;
    //     }
    // }

    // set<int> total;
    // for (int i = 0; i < n; i++) {
    //     vector<int> notset;
    //     int num = v[i];
    //     for (int j = 0; j < 22; j++) {
    //         if (!(num & 1)) notset.push_back(j);
    //         num >>= 1;
    //     }

    //     set<int> s;
    //     for (int b : notset) {
    //         auto it = upper_bound(bits[b].begin(), bits[b].end(), i);
    //         if (it != bits[b].end()) {
    //             s.insert(*it);
    //         }
    //     }

    //     int tmp = v[i];
    //     total.insert(tmp);
        
    //     for (int index : s) {
    //         tmp |= v[index];
    //         total.insert(tmp);
    //     }
    // }

    // cout << total.size() << endl;
    
    set<int> total;
    set<int> all;
    for (int i = 0; i < n; i++) {
        set<int> t;
        all.insert(0);
        for (int a : all) {
            t.insert(a | v[i]);
            total.insert(a | v[i]);
        }
        all = t;
    }

    cout << total.size() << endl;
    return 0;
}