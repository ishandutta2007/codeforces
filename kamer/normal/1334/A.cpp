#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <tuple>
#include <utility>
#include <queue>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
using namespace std;
typedef long long ll;

int main(void) {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> p(n);
        vector<int> c(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i] >> c[i];
        }
        bool ok = true;
        if (p[0] < c[0]) {
            cout << "NO\n";
            continue;
        }
        for (int i = 0; i < n - 1; i++) {
            if (p[i + 1] < p[i] || c[i + 1] < c[i] || c[i + 1] - c[i] > p[i + 1] - p[i]) {
                ok = false;
            }
        }
        if (ok) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}