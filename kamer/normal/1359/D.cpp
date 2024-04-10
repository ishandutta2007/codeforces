#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int bestSum = 0;
    for (int x = 1; x <= 31; x++) {
        vector<tuple<int, int>> ranges;
        int lRange = -1;
        for (int i = 0; i < n; i++) {
            if (a[i] > x) {
                if (lRange != -1) {
                    ranges.push_back(make_tuple(lRange, i - 1));
                    lRange = -1;
                }
            } else {
                if (lRange == -1) {
                    lRange = i;
                }
            }
        }
        if (lRange != -1) {
            ranges.push_back(make_tuple(lRange, n - 1));
        }

        for (auto range : ranges) {
            int l = get<0>(range), r = get<1>(range);
            vector<int> sums(r - l + 2), maxSums(r - l + 1);
            sums[0] = 0;
            for (int i = l; i <= r; i++) {
                sums[i - l + 1] = sums[i - l] + a[i];
            }
            maxSums[r - l] = sums[r - l + 1];
            for (int i = r - l - 1; i >= 0; i--) {
                maxSums[i] = max(maxSums[i + 1], sums[i + 1]);
            }
            for (int i = 0; i < r - l; i++) {
                bestSum = max(bestSum, maxSums[i] - sums[i] - x);
            }
        }
    }
    cout << bestSum << "\n";
}