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
        int result = 0;
        int n, m;
        cin >> n >> m;
        if (n == 0) {
            cout << m + 1 << "\n";
            continue;
        }

        
        int k = -1;
        int curr_power = 1;
        while (n >= curr_power) {
            curr_power *= 2;
            k++;
        }

        result = m & (~((1 << (k + 1)) - 1));
        m = m & ((1 << (k + 1)) - 1);
        bool add_one = true;
        for (int i = k; i >= 0; i--) {
            int bit_mask = 1 << i;
            if (m == 2 * bit_mask - 1) {
                result += m + 1;
                add_one = false;
                break;
            }

            if (n & bit_mask) {
                if (m & bit_mask) {
                    // empty, gonna be 0
                } else {
                    add_one = false;
                    break;
                }
            } else {
                if (m & bit_mask) {
                    result = result | bit_mask;
                } else {
                    // empty, gonna be 0
                }
            }

            m = m & (~bit_mask);
        }

        if (add_one) result++;

        cout << result << "\n";
    }
}