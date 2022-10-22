#include <iostream>
#include <algorithm>
#include <utility>
#include <tuple>
#include <string>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
using namespace std;
typedef long long ll;

int main(void) {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string aS, bS;
        cin >> aS >> bS;
        vector<bool> a(n, false), b(n, false);
        for (int i = 0; i < n; i++) {
            if (aS[i] == '1') a[i] = true;
            if (bS[i] == '1') b[i] = true;
        }
        vector<int> ops;
        for (int i = 0; i < n; i++) {
            bool val = false;
            if (i % 2 == 0) {
                val = a[i / 2];
            } else {
                val = !a[n - 1 - i / 2];
            }
            if (val == b[n - 1 - i]) {
                ops.push_back(1);
            }
            ops.push_back(n - i);
        }
        cout << ops.size();
        for (auto op : ops) cout << " " << op;
        cout << "\n";
    }
}