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
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        vector<int> oddPos;
        for (int i = 0; i < n; i++) {
            if (a[i] % 2 == 1) oddPos.push_back(i);
        }

        int k = oddPos.size();
        vector<int> target1, target2;
        if (n % 2 == 0) {
            if (k != n / 2) {
                cout << "-1\n";
                continue;
            }

            for (int i = 0; i < n / 2; i++) {
                target1.push_back(2 * i);
                target2.push_back(2 * i + 1);
            }
        } else {
            if ((k != n / 2) && (k != (n / 2 + 1))) {
                cout << "-1\n";
                continue;
            }

            if (k == n / 2) {
                for (int i = 0; i < n / 2; i++) {
                    target1.push_back(2 * i + 1);
                }
            } else {
                for (int i = 0; i <= n / 2; i++) {
                    target1.push_back(2 * i);
                }
            }
        }

        ll bestCount = 0;
        for (int i = 0; i < oddPos.size(); i++) {
            bestCount += (ll) (max(target1[i] - oddPos[i], oddPos[i] - target1[i]));
        }

        if (target2.size() > 0) {
            ll bestCount2 = 0;
            for (int i = 0; i < oddPos.size(); i++) {
                bestCount2 += (ll) (max(target2[i] - oddPos[i], oddPos[i] - target2[i]));
            }

            bestCount = min(bestCount, bestCount2);
        }

        cout << bestCount << "\n";
    }
}