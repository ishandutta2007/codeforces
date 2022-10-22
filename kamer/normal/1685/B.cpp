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
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        string s;
        cin >> s;

        int count_a = 0, count_b = 0;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (s[i] == 'A') count_a++;
            else count_b++;
        }

        if (count_a != a + c + d || count_b != b + c + d) {
            cout << "NO\n";
            continue;
        }

        if (c == 0 && d == 0) {
            cout << "YES\n";
            continue;
        }

        if (s[0] == 'B') {
            for (int i = 0; i < n; i++) {
                s[i] = 'A' + 'B' - s[i];
            }

            swap(a, b);
            swap(c, d);
        }

        vector<tuple<char, int>> blocks;

        char curr_c = 'A';
        int curr_begin = 0;
        int curr_index = 0;
        while (curr_index < n) {

            if (s[curr_index] != curr_c) {
                blocks.emplace_back(curr_c, curr_index - curr_begin);
                curr_begin = curr_index;
                curr_c = s[curr_index];
            }

            if (curr_index == n - 1) {
                blocks.emplace_back(curr_c, curr_index - curr_begin + 1);
                break;
            }


            curr_index++;
        }

        vector<int> normal_sums;
        vector<int> bonus_a_sums;
        vector<int> bonus_b_sums;
        curr_begin = 0;
        int k = blocks.size();
        
        curr_index = 1;
        while (curr_index < k) {
            if ((curr_index == k - 1) || (get<1>(blocks[curr_index]) > 1)) {
                if ((curr_begin % 2) == (curr_index % 2)) {
                    normal_sums.emplace_back((curr_index - curr_begin) / 2);
                } else {
                    if (get<0>(blocks[curr_index]) == 'A') {
                        bonus_b_sums.emplace_back((curr_index - curr_begin) / 2);
                    } else {
                        bonus_a_sums.emplace_back((curr_index - curr_begin) / 2);
                    }
                }
                curr_begin = curr_index;
            }

            curr_index++;
        }

        int total_sum = 0;
        for (auto el : normal_sums) total_sum += el;
        for (auto el : bonus_a_sums) total_sum += el;
        for (auto el : bonus_b_sums) total_sum += el;

        int extra_contrib = (c + d) - total_sum;

        if (extra_contrib <= 0) {
            cout << "YES\n";
            continue;
        }

        if (extra_contrib > bonus_a_sums.size() + bonus_b_sums.size()) {
            cout << "NO\n";
            continue;
        }

        int a_index = 0;
        int a_sum = 0;
        int b_index = extra_contrib;
        int b_sum = 0;

        sort(bonus_a_sums.begin(), bonus_a_sums.end());
        sort(bonus_b_sums.begin(), bonus_b_sums.end());
        
        for (int i = 0; i < min(extra_contrib, (int) bonus_b_sums.size()); i++) b_sum += bonus_b_sums[i];

        bool done = false;
        while (b_index >= 0) {
            if (a_index <= bonus_a_sums.size() && b_index <= bonus_b_sums.size()) {
                if ((c >= a_sum + a_index) && (d >= b_sum + b_index)) {
                    cout << "YES\n";
                    done = true;
                    break;
                }
            }
            
            if (a_index < bonus_a_sums.size()) a_sum += bonus_a_sums[a_index];
            if ((b_index <= bonus_b_sums.size()) && (b_index > 0)) b_sum -= bonus_b_sums[b_index - 1];
            a_index++, b_index--;
        }

        if (!done) {
            cout << "NO\n";
        }
        

    }
}