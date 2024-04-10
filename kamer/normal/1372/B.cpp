#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <utility>
using namespace std;

void solve() {
    int n; cin >> n;
    for (int x = 2; x < 34000; x++) {
        if (n % x == 0) {
            cout << n / x << " " << n / x * (x - 1) << "\n";
            return;
        }
    }

    cout << "1 " << n - 1 << "\n";
}

int main(void) {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}