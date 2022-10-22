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
#include <cstdlib>
using namespace std;
typedef long long ll;

bool greaterr(vector<int>& a, vector<int>& b) {
    int count = 0;
    for (int i = 0; i < 5; i++) {
        if (a[i] < b[i]) count++;
    }
    return (count >= 3);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(14);
    int t;
    cin >> t;

    srand(time(NULL));
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> r(n, vector<int>(5, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 5; j++) {
                cin >> r[i][j];
            }
        }

        vector<int> rem(n, 0);
        for (int i = 0; i < n; i++) rem[i] = i;
        while (rem.size() > 1) {
            int k = rem.size();
            int small_index = rand() % k;
            int index = rem[small_index];
            vector<int> new_rem;
            for (auto i : rem) {
                if (i != index) {
                    if (!greaterr(r[index], r[i])) {
                        new_rem.push_back(i);
                    }
                }
            }

            rem = new_rem;

            if (rem.size() == 0) {
                rem.push_back(index);
            }
        }

        int index = rem[0];
        bool yes = true;
        for (int i = 0; i < n; i++) {
            if (i != index) {
                if (!greaterr(r[index], r[i])) {
                    yes = false;
                    break;
                }
            }
        }

        if (yes) {
            cout << index + 1 << "\n";
        } else {
            cout << "-1\n";
        }
    }
}