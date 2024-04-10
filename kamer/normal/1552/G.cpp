#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <string>
#include <utility>
#include <iomanip>
#include <fstream>
#include <cmath>
using namespace std;
typedef long long ll;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(14);
    
    int n, k;
    cin >> n >> k;

    if (n == 1) {
        cout << "ACCEPTED\n";
        return 0;
    }

    vector<ll> powers(n, 1);
    for (int i = 1; i < n; i++) {
        powers[i] = powers[i - 1] * 2;
    }

    vector<ll> subset_masks(k, 0);
    vector<bool> seen(n, false);
    int seen_count = 0;
    for (int i = 0; i < k; i++) {
        int q;
        cin >> q;
        for (int j = 0; j < q; j++) {
            int x;
            cin >> x;
            x--;
            subset_masks[i] |= powers[x];
            if (!seen[x]) {
                seen[x] = true;
                seen_count++;
            }
        }
    }

    if (seen_count < n) {
        cout << "REJECTED\n";
        return 0;
    }

    ll current_mask = 0;
    vector<ll> possibs(1, 0);
    for (int i = 0; i < k; i++) {
        ll curr_subset_mask = subset_masks[i];
        ll overlap_mask = curr_subset_mask & current_mask;
        ll new_mask = curr_subset_mask ^ overlap_mask;

        int curr_subset_mask_size = __builtin_popcountll(curr_subset_mask);
        int new_mask_size = __builtin_popcountll(new_mask);
        vector<ll> ordered_curr_subset_masks(curr_subset_mask_size + 1, curr_subset_mask);
        for (int j = curr_subset_mask_size - 1; j >= 0; j--) {
            ordered_curr_subset_masks[j] = ordered_curr_subset_masks[j + 1] &
                                           (ordered_curr_subset_masks[j + 1] - 1);
        }

        // cout << "new curr " << new_mask_size << " " << curr_subset_mask_size << endl;

        vector<ll> new_possibs(possibs.size() * (new_mask_size + 1));
        int new_possibs_count = 0;
        for (auto possib : possibs) {
            int curr_num_ones = __builtin_popcountll(possib & overlap_mask);
            possib &= (~overlap_mask);
            for (int total_num_ones = curr_num_ones; total_num_ones <= curr_num_ones + new_mask_size; total_num_ones++) {
                new_possibs[new_possibs_count++] = possib |
                                                   ordered_curr_subset_masks[total_num_ones];
            }
        }

        possibs = new_possibs;
        current_mask |= curr_subset_mask;
        // cout << "possibs size " << possibs.size() << endl;
    }

    bool exists_unordered = false;
    vector<ll> ordered_possibs(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        ordered_possibs[i] = ordered_possibs[i - 1] | powers[n - i];
    }
    for (auto possib : possibs) {
        if (!binary_search(ordered_possibs.begin(), ordered_possibs.end(), possib)) {
            exists_unordered = true;
            break;
        }
    }

    if (exists_unordered) {
        cout << "REJECTED\n";
    } else {
        cout << "ACCEPTED\n";
    }
}