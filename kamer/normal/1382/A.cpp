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
        int n, m;
        cin >> n >> m;
        unordered_set<int> a;
        int val = -1;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            a.insert(x);
        }
        for (int i = 0; i < m; i++) {
            int x; cin >> x;
            if (a.find(x) != a.end()) {
                val = x;
            }
        }
        if (val != -1) {
            cout << "YES\n 1 " << val << "\n";
        } else {
            cout << "NO\n";
        }
    }
}