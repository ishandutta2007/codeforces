#include <iostream>
#include <algorithm>
#include <string>
#include <utility>
#include <tuple>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
using namespace std;
typedef long long ll;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        vector<int> isPeak(n, 0);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 1; i < n - 1; i++) {
            if (a[i] > a[i - 1] && a[i] > a[i + 1]) isPeak[i] = 1;
        }

        int maxPeaks = 0;
        int bestL = 0;
        int currPeaks;
        for (int i = 1; i < k - 1; i++) maxPeaks += isPeak[i];
        currPeaks = maxPeaks;
        for (int i = k; i < n; i++) {
            currPeaks = currPeaks + isPeak[i - 1] - isPeak[i - k + 1];
            if (currPeaks > maxPeaks) {
                maxPeaks = currPeaks;
                bestL = i - k + 1;
            }
        }

        cout << maxPeaks + 1 << " " << bestL + 1 << "\n";
    }
}