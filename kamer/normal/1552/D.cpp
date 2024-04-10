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
    vector<int> powers(25, 1);
    for (int i = 1; i < 25; i++) powers[i] = 2 * powers[i - 1];

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        
        bool cycle = false;
        for (int mask = 1; mask < powers[n]; mask++) {
            int submask_length  = 0;
            vector<int> a_rem;
            for (int i = 0; i < n; i++) {
                if (mask & powers[i]) {
                    submask_length++;
                    a_rem.push_back(a[i]);
                }
            }

            for (int submask = 0; submask < powers[submask_length]; submask++) {
                int sum = 0;
                for (int i = 0; i < submask_length; i++) {
                    if (submask & powers[i]) sum += a_rem[i];
                    else sum -= a_rem[i];
                }

                if (sum == 0) {
                    cycle = true;
                    break;
                }
            }

            if (cycle) break;
        }

        if (cycle) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}