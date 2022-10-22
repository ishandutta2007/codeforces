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
    int n;
    cin >> n;
    vector<int> c(n), p(n);
    for (int i = 0; i < n; i++) cin >> c[i] >> p[i];
    int k;
    cin >> k;
    vector<tuple<int, int>> r(k);
    for (int i = 0; i < k; i++) {
        int a;
        cin >> a;
        r[i] = { a, i + 1 };
    }
    sort(r.begin(), r.end());

    int totalMoney = 0;
    vector<tuple<int, int>> results;
    vector<bool> available(n, true);
    for (int i = 0; i < k; i++) {
        int bestIndex = -1;
        int bestSum = -1;
        for (int j = 0; j < n; j++) {
            if (available[j] && (c[j] <= get<0>(r[i]))) {
                if (bestSum <= p[j]) {
                    bestIndex = j;
                    bestSum = p[j];
                }
            }
        }

        if (bestIndex != -1) {
            results.emplace_back(bestIndex + 1, get<1>(r[i]));
            totalMoney += bestSum;
            available[bestIndex] = false;
        }
    }

    cout << results.size() << " " << totalMoney << "\n";
    for (auto [x, y] : results) {
        cout << x << " " << y << "\n";
    }
}