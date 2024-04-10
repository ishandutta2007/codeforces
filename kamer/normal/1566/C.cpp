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
        string s1, s2;
        cin >> s1 >> s2;
        vector<bool> skip(n, false);
        vector<bool> used(n, false);
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (s1[i] != s2[i]) {
                res += 2;
                skip[i] = true;
                used[i] = true;
            }

            if (s1[i] == '0') used[i] = true;
        }

        int currentIndex = 0;
        while (currentIndex < n) {
            if (skip[currentIndex]) {
                currentIndex++;
                continue;
            }

            int lastIndex = currentIndex;
            while (lastIndex < n && !skip[lastIndex]) lastIndex++;

            for (int i = currentIndex; i < lastIndex; i++) {
                if (s1[i] == '0') {
                    if (i > 0 && !used[i - 1]) {
                        used[i - 1] = true;
                        res += 2;
                    } else {
                        if (i + 1 < n && !used[i + 1]) {
                            used[i + 1] = true;
                            res += 2;
                        } else {
                            res += 1;
                        }
                    }
                }
            }

            currentIndex = lastIndex;
        }

        cout << res << "\n";
    }
}