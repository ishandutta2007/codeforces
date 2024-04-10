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
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<vector<int>>> occurence(2, vector<vector<int>>(52, vector<int>(n, -1)));
        vector<string> strings(n);
        for (int i = 0; i < n; i++) {
            cin >> strings[i];
            int k = strings[i].length();
            for (int j = 0; j < k; j++) {
                auto c = strings[i][j];
                int c_i = c - 'a';
                if ('A' <= c && c <= 'Z') c_i = c - 'A' + 26;
                if (occurence[0][c_i][i] == -1) {
                    occurence[0][c_i][i] = j;
                } else {
                    occurence[1][c_i][i] = j;
                }
            }
        }

        vector<vector<int>> best_length(strings[0].length(), vector<int>(1 << n, 0));
        vector<vector<int>> opt_index(strings[0].length(), vector<int>(1 << n, -1));
        vector<vector<int>> opt_bit_mask(strings[0].length(), vector<int>(1 << n, -1));
        int max_length = 0;
        int max_index = -1;
        int max_bit_mask = -1;
        for (int i = strings[0].length() - 1; i >= 0; i--) {
            int x = 1;
            int c = strings[0][i] - 'a';
            if (strings[0][i] >= 'A' && strings[0][i] <= 'Z') c = strings[0][i] - 'A' + 26;
            if (occurence[0][c][0] == i) x = 0;
            for (int rem_bit_mask = 0; rem_bit_mask < (1 << (n - 1)); rem_bit_mask++) {
                int bit_mask = 2 * rem_bit_mask + x;
                vector<int> occ_ind(n);
                for (int power = 0; power < n; power++) {
                    if (bit_mask & (1 << power)) {
                        occ_ind[power] = occurence[1][c][power];
                    } else {
                        occ_ind[power] = occurence[0][c][power];
                    }
                }
                
                bool should_continue = false;
                for (auto occ_index : occ_ind) {
                    if (occ_index == -1) {
                        should_continue = true;
                        break;
                    }
                }

                if (should_continue) {
                    continue;
                }

                best_length[i][bit_mask] = 1;
                if (max_length < 1) {
                    max_length = 1;
                    max_index = i;
                    max_bit_mask = bit_mask;
                }

                for (int next_c = 0; next_c < 52; next_c++) {
                    bool none_found = false;
                    int next_bit_mask = 0;
                    int first_string_next = -1;
                    for (int string_index = 0; string_index < n; string_index++) {
                        if (occurence[0][next_c][string_index] <= occ_ind[string_index]) {
                            if (occurence[1][next_c][string_index] <= occ_ind[string_index]) {
                                none_found = true;
                                break;
                            } else {
                                next_bit_mask += (1 << string_index);
                                if (string_index == 0) {
                                    first_string_next = occurence[1][next_c][string_index];
                                }
                            }
                        } else if (string_index == 0) {
                            first_string_next = occurence[0][next_c][string_index];
                        }
                    }

                    if (none_found) {
                        continue;
                    }
                    
                    if (best_length[i][bit_mask] < best_length[first_string_next][next_bit_mask] + 1) {
                        best_length[i][bit_mask] = best_length[first_string_next][next_bit_mask] + 1;
                        opt_index[i][bit_mask] = first_string_next;
                        opt_bit_mask[i][bit_mask] = next_bit_mask;
                    }

                    if (max_length < best_length[i][bit_mask]) {
                        max_length = best_length[i][bit_mask];
                        max_index = i;
                        max_bit_mask = bit_mask;
                    }
                }
            }
        }

        cout << max_length << "\n";
        if (max_length == 0) {
            cout << "\n";
            continue;
        }

        while (max_index != -1) {
            cout << strings[0][max_index];
            int temp_max_index = opt_index[max_index][max_bit_mask];
            max_bit_mask = opt_bit_mask[max_index][max_bit_mask];
            max_index = temp_max_index;
        }
        cout << "\n";
    }
}