#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <algorithm>
#include <utility>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

using namespace std;
typedef long long ll;
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;


typedef tree<
int,
null_type,
greater<int>,
rb_tree_tag,
tree_order_statistics_node_update>
rev_ordered_set;


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(14);
    int n, m;
    cin >> n >> m;
    vector<vector<tuple<int, int>>> ver(2, vector<tuple<int, int>>());
    vector<vector<tuple<int, int>>> hor(2, vector<tuple<int, int>>());
    ll regions = 1;
    for (int i = 0; i < n; i++) {
        int y, l, r;
        cin >> y >> l >> r;
        if (l <= 0) {
            hor[0].emplace_back(y, r);
        } else {
            hor[1].emplace_back(y, l);
        }

        if (l <= 0 && r >= 1000000) regions++;
    }

    for (int i = 0; i < m; i++) {
        int x, l, r;
        cin >> x >> l >> r;
        if (l <= 0) {
            ver[0].emplace_back(r, x);
        } else {
            ver[1].emplace_back(l, x);
        }

        if (l <= 0 && r >= 1000000) regions++;
    }

    int vIndex;

    // vs00
    sort(ver[0].begin(), ver[0].end(), greater<tuple<int, int>>());
    sort(hor[0].begin(), hor[0].end(), greater<tuple<int, int>>());

    ordered_set vs00;

    vIndex = 0;
    for (int hIndex = 0; hIndex < hor[0].size(); hIndex++) {
        auto [y, r] = hor[0][hIndex];
        while (vIndex < ver[0].size() && get<0>(ver[0][vIndex]) >= y) {
            vs00.insert(get<1>(ver[0][vIndex]));
            vIndex++;
        }
        regions += vs00.order_of_key(r + 1);
    }

    // vs01
    // sort(ver[0].begin(), ver[0].end(), greater<tuple<int, int>>());
    sort(hor[1].begin(), hor[1].end(), greater<tuple<int, int>>());

    rev_ordered_set vs01;

    vIndex = 0;
    for (int hIndex = 0; hIndex < hor[1].size(); hIndex++) {
        auto [y, r] = hor[1][hIndex];
        while (vIndex < ver[0].size() && get<0>(ver[0][vIndex]) >= y) {
            vs01.insert(get<1>(ver[0][vIndex]));
            vIndex++;
        }
        regions += vs01.order_of_key(r - 1);
    }

    // vs10
    sort(ver[1].begin(), ver[1].end());
    // sort(hor[0].begin(), hor[0].end(), greater<tuple<int, int>>());

    ordered_set vs10;

    vIndex = 0;
    for (int hIndex = hor[0].size() - 1; hIndex >= 0; hIndex--) {
        auto [y, r] = hor[0][hIndex];
        while (vIndex < ver[1].size() && get<0>(ver[1][vIndex]) <= y) {
            vs10.insert(get<1>(ver[1][vIndex]));
            vIndex++;
        }
        regions += vs10.order_of_key(r + 1);
    }

    // vs11
    // sort(ver[0].begin(), ver[0].end(), greater<tuple<int, int>>());
    // sort(hor[0].begin(), hor[0].end(), greater<tuple<int, int>>());

    rev_ordered_set vs11;

    vIndex = 0;
    for (int hIndex = hor[1].size() - 1; hIndex >= 0; hIndex--) {
        auto [y, r] = hor[1][hIndex];
        while (vIndex < ver[1].size() && get<0>(ver[1][vIndex]) <= y) {
            vs11.insert(get<1>(ver[1][vIndex]));
            vIndex++;
        }
        regions += vs11.order_of_key(r - 1);
    }

    cout << regions << "\n";

}