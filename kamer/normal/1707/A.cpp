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
#include <complex>
using namespace std;
typedef long long ll;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(14);
    int t;
    cin >> t;
    while (t--) {
        int n, q_orig;
        cin >> n >> q_orig;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        int l_num_skips = -1, r_num_skips = n;
        int max_num_ops = 0;
        while (r_num_skips > l_num_skips + 1) {
            int num_skips = (l_num_skips + r_num_skips) / 2;
            int q = q_orig;
            int curr_num_skips = 0;
            bool reached_end = true;
            int num_ops = 0;
            for (int i = 0; i < n; i++) {
                if (a[i] > q) {
                    if (curr_num_skips < num_skips) {
                        curr_num_skips++;
                    } else {
                        q--;
                        num_ops++;
                    }
                } else {
                    num_ops++;
                }

                if (q == 0 && i < n - 1) {
                    reached_end = false;
                    break;
                }
            }

            max_num_ops = max(max_num_ops, num_ops);
            if (reached_end) {
                r_num_skips = num_skips;
            } else {
                l_num_skips = num_skips;
            }
        }

        string s(n, '0');
        int q = q_orig;
        int curr_num_skips = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] > q && curr_num_skips < r_num_skips) {
                curr_num_skips++;
            } else {
                s[i] = '1';
                if (a[i] > q) {
                    q--;
                }
            }

            if (q == 0) {
                break;
            }
        }

        cout << s << "\n";

    }
}