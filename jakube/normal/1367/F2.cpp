#include "bits/stdc++.h"
using namespace std;

template<typename T>
istream& operator>>(istream& is, vector<T>& v) {
    for (auto& x : v)
        is >> x;
    return is;
}

int solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    cin >> v;
    
    map<int, int> reduce_map;
    for (auto x : v) {
        reduce_map[x]++;
    }
    vector<int> reduce_vec;
    vector<int> duplicate_cnts;
    for (auto [x, c] : reduce_map) {
        reduce_vec.push_back(x);
        duplicate_cnts.push_back(c);
    }
    for (auto& x : v)
        x = lower_bound(reduce_vec.begin(), reduce_vec.end(), x) - reduce_vec.begin();

    array<vector<pair<int, int>>, 3> cnts;
    for (int i = 0; i < 3; i++) {
        cnts[i] = vector<pair<int, int>>(reduce_map.size(), {0, 0});
    }
    // with_prev, with_out, full

    for (int x : v) {
        // with_previous
        pair<int, int> res{1, 1};
        if (x) {
            if (cnts[0][x-1].second == duplicate_cnts[x-1])
                res = max(res, {cnts[0][x-1].first + 1, 1});
            if (cnts[2][x-1].second == duplicate_cnts[x-1])
                res = max(res, {cnts[2][x-1].first + 1, 1});
            res = max(res, {cnts[1][x-1].first + 1, 1});
        }
        // option 2: simple increase
        res = max(res, {cnts[0][x].first + 1, cnts[0][x].second + 1});
        cnts[0][x] = res;

        // with_out
        cnts[1][x] = {cnts[1][x].first + 1, cnts[1][x].first + 1};

        // full
        if (cnts[2][x].first) {
            cnts[2][x].first++;
            cnts[2][x].second++;
        } else {
            pair<int, int> res{1, 1};
            if (x) {
                if (cnts[0][x-1].second == duplicate_cnts[x-1])
                    res = max(res, {cnts[0][x-1].first + 1, 1});
                if (cnts[2][x-1].second == duplicate_cnts[x-1])
                    res = max(res, {cnts[2][x-1].first + 1, 1});
                res = max(res, {cnts[1][x-1].first + 1, 1});
            }
            cnts[2][x] = res;
        }
    }
    int ma = (*max_element(cnts[0].begin(), cnts[0].end())).first;
    int ma2 = (*max_element(cnts[1].begin(), cnts[1].end())).first;
    int ma3 = (*max_element(cnts[2].begin(), cnts[2].end())).first;
    return n - max({ma, ma2, ma3});
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int testcase = 1; testcase <= T; testcase++) {
        cout << solve() << '\n';
    }
}