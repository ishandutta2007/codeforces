#include <iostream>
#include <vector>
#include <tuple>
#include <string>
#include <algorithm>
#include <utility>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
using namespace std;
typedef long long ll;

ll dist(ll a, ll b, ll c) {
    return (a - b) * (a - b) + (a - c) * (a - c) + (b - c) * (b - c);
}

int main(void) {
    int t;
    cin >> t;
    while (t--) {
        vector<int> n(3);
        cin >> n[0] >> n[1] >> n[2];
        vector<vector<int>> w(3);
        for (int i = 0; i < 3; i++) {
            w[i] = vector<int>(n[i], 0);
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < n[i]; j++) {
                cin >> w[i][j];
            }
        }

        for (int i = 0; i < 3; i++) sort(w[i].begin(), w[i].end());

        ll result = ((ll) 2) * ((ll) 1000000000000000000) + ((ll) 3);
        for (int c1 = 0; c1 < 2; c1++) {
            for (int c2 = c1 + 1; c2 < 3; c2++) {
                int c3 = 3 - c1 - c2;
                int p1 = 0, p2 = 0, p3 = 0;
                while (p1 < w[c1].size() && p2 < w[c2].size()) {
                    int v1 = w[c1][p1], v2 = w[c2][p2];
                    while (p3 < w[c3].size() && w[c3][p3] < ((v1 + v2) / 2)) {
                        p3++;
                    }
                    if (p3 > 0) {
                        result = min(result, dist(v1, v2, w[c3][p3 - 1]));
                    }
                    if (p3 < w[c3].size()) {
                        result = min(result, dist(v1, v2, w[c3][p3]));
                    }
                    if (p1 == w[c1].size() - 1) p2++;
                    else if (p2 == w[c2].size() - 1) p1++;
                    else if (w[c1][p1] < w[c2][p2]) p1++;
                    else p2++;
                }
            }
        }

        cout << result << "\n";
    }
}