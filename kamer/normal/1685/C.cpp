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
        string s;
        cin >> s;

        vector<int> pref(2 * n + 1, 0);
        for (int i = 0; i < 2 * n; i++) {
            if (s[i] == '(') pref[i + 1] = pref[i] + 1;
            else pref[i + 1] = pref[i] - 1;
        }

        // check 0
        bool pref_positive = true;
        for (int i = 0; i < 2 * n + 1; i++) {
            if (pref[i] < 0) {
                pref_positive = false;
                break;
            }
        }

        if (pref_positive) {
            cout << "0\n";
            continue;
        }

        // check 1
        int min_neg_pos = -1;
        int max_neg_pos = -1;
        
        for (int i = 0; i < 2 * n + 1; i++) {
            if (pref[i] < 0) {
                min_neg_pos = i;
                break;
            }
        }

        for (int i = 2 * n; i >= 0; i--) {
            if (pref[i] < 0) {
                max_neg_pos = i;
                break;
            }
        }

        int max_int_val = -1;
        int max_int_val_pos = -1;
        for (int i = min_neg_pos; i <= max_neg_pos; i++) {
            if (pref[i] > max_int_val) {
                max_int_val_pos = i;
                max_int_val = pref[i];
            }
        }

        int max_sub_val = -1;
        int max_sub_val_pos = -1;
        for (int i = 0; i < min_neg_pos; i++) {
            if (pref[i] > max_sub_val) {
                max_sub_val_pos = i;
                max_sub_val = pref[i];
            }
        }

        int max_sup_val = -1;
        int max_sup_val_pos = -1;
        for (int i = max_neg_pos + 1; i < 2 * n + 1; i++) {
            if (pref[i] > max_sup_val) {
                max_sup_val_pos = i;
                max_sup_val = pref[i];
            }
        }

        if (max_sub_val + max_sup_val >= max_int_val) {
            cout << "1\n";
            cout << max_sub_val_pos + 1 << " " << max_sup_val_pos << "\n";
            continue;
        }

        cout << "2\n1 " << max_int_val_pos << "\n" << max_int_val_pos + 1 << " " << 2 * n << "\n";
    }
}