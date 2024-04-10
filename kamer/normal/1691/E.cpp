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
using namespace std;
typedef long long ll;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(14);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<tuple<int, int, int>> intervals(n);
        vector<int> endpoints(2 * n);
        for (int i = 0; i < n; i++) {
            int c, l, r;
            cin >> c >> l >> r;
            intervals[i] = { c, l, r };
            endpoints[2 * i] = l;
            endpoints[2 * i + 1] = r;
        }

        sort(endpoints.begin(), endpoints.end());
        unordered_map<int, int> compression;
        int curr_counter = 0;
        for (int i = 0; i < 2 * n; i++) {
            if (compression.find(endpoints[i]) == compression.end()) {
                compression[endpoints[i]] = curr_counter++;
            }
        }

        int num_endpoints = curr_counter;
        vector<vector<unordered_multiset<int>>> left(num_endpoints, vector<unordered_multiset<int>>(2, unordered_multiset<int>()));

        for (auto [c, l, r] : intervals) {
            left[compression[l]][c].insert(compression[r]);
        }

        int num_components = 0;
        unordered_multiset<int> free_red;
        unordered_multiset<int> free_blue;
        unordered_multiset<int> mixed_red;
        unordered_multiset<int> mixed_blue;

        for (int i = 0; i < num_endpoints; i++) {
            for (auto red_end : left[i][0]) {
                free_red.insert(red_end);
            }

            for (auto blue_end : left[i][1]) {
                free_blue.insert(blue_end);
            }

            if ((free_red.size() > 0 || mixed_red.size() > 0) &&
                (free_blue.size() > 0 || mixed_blue.size() > 0)) {
                for (auto red_end : free_red) {
                    mixed_red.insert(red_end);
                }

                for (auto blue_end : free_blue) {
                    mixed_blue.insert(blue_end);
                }

                free_red.clear();
                free_blue.clear();
            }
            
            num_components += free_red.erase(i);
            num_components += free_blue.erase(i);

            if (mixed_blue.size() > 0 || mixed_red.size() > 0) {
                mixed_blue.erase(i);
                mixed_red.erase(i);

                if (mixed_blue.size() == 0 && mixed_red.size() == 0) {
                    num_components++;
                }
            }
        }

        cout << num_components << "\n";

    }
}