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
    vector<int> c(n * k, -1);
    for (int i = 0; i < n * k; i++) {
        cin >> c[i];
        c[i]--;
    }
    vector<int> a(n, -1);
    vector<int> b(n, -1);

    vector<bool> seen(n, false);
    int color_count = 0;

    for (int pass = 0; pass < ((n - 1) / (k - 1)) + 2; pass++) {
        int curr_index = 0;
        for (int run = 0; run < k - 1; run++) {
            if (color_count == n) {
                break;
            }

            vector<int> color_index(n, -1);
            while (true) {
                if (!seen[c[curr_index]]) {
                    if (color_index[c[curr_index]] != -1) {
                        a[c[curr_index]] = color_index[c[curr_index]];
                        b[c[curr_index]] = curr_index;
                        seen[c[curr_index]] = true;
                        color_count++;
                        break;
                    } else {
                        color_index[c[curr_index]] = curr_index;
                    }
                }

                curr_index++;
            }
        }

        if (color_count == n) {
            break;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] + 1 << " " << b[i] + 1 << "\n";
    }

}