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
        vector<int> p(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i];
            p[i]--;
        }

        vector<int> p_cycle(n, -1);
        int curr_cycle = 0;
        for (int i = 0; i < n; i++) {
            if (p_cycle[i] != -1) {
                continue;
            }
            
            int curr_index = i;
            while (p_cycle[curr_index] == -1) {
                p_cycle[curr_index] = curr_cycle;
                curr_index = p[curr_index];
            }

            curr_cycle++;
        }

        int num_cycles = curr_cycle;

        vector<int> p_neg(n);
        for (int i = 0; i < n; i++) {
            p_neg[p[i]] = i;
        }

        for (int cycle_num = 1; cycle_num < num_cycles; cycle_num++) {
            int first_cycle_index = 0;
            int other_cycle_index = -1;
            
            if (p_cycle[1] != 0) {
                other_cycle_index = 1;
            } else {
                first_cycle_index = p_neg[first_cycle_index];
                while (first_cycle_index != 0) {
                    if (p_cycle[first_cycle_index - 1] != 0) {
                        other_cycle_index = first_cycle_index - 1;
                        break;
                    } else if (first_cycle_index < n - 1 && p_cycle[first_cycle_index + 1] != 0) {
                        other_cycle_index = first_cycle_index + 1;
                        break;
                    }

                    first_cycle_index = p_neg[first_cycle_index];
                }
            }

            swap(p_neg[first_cycle_index], p_neg[other_cycle_index]);
            int running_cycle_index = p_neg[first_cycle_index];
            while (running_cycle_index != first_cycle_index) {
                p_cycle[running_cycle_index] = 0;
                running_cycle_index = p_neg[running_cycle_index];
            }
        }

        cout << "1 ";
        int q_index = p_neg[0];
        while (q_index != 0) {
            cout << q_index + 1 << " ";
            q_index = p_neg[q_index];
        }
        cout << "\n";
    }
}