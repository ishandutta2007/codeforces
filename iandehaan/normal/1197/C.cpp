#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> jumps;
    int a[n];
    cin >> a[0];
    for (int i = 1; i < n; i++) {
        cin >> a[i];
        jumps.push_back(make_pair(a[i]-a[i-1], i-1));
    }
    sort(jumps.begin(), jumps.end());

    int ind = jumps.size()-1;
    uint64_t out = 0;
    unordered_set<int> jumpInds;
    while (k > 1) {
        int jumpInd = jumps[ind].second;
        jumpInds.insert(jumpInd);
        k--;
        ind--;
    }
    int curMin = 1e9;
    int curMax = 0;
    for (int i = 0; i < n; i++) {
        curMin = min(curMin, a[i]);
        curMax = max(curMax, a[i]);

        if (jumpInds.find(i) != jumpInds.end()) {
            out += curMax-curMin;
            curMin = 1e9;
            curMax = 0;
        }
    }
    out += curMax - curMin;
    cout << out << endl;
}