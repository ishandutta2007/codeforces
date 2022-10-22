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
using namespace std;
typedef long long ll;

// assumes n is odd
void solve(int n) {
    cout << "YES\n";
    cout << n - 2 << "\n";
    for (int j = 2; j <= n - 1; j += 2) {
        cout << "1 " << j << " " << j + 1 << "\n";
    }
    for (int j = 2; j < n - 1; j += 2) {
        cout << j << " " << j + 1 << " " << n << "\n";
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(14);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    if (n % 2 == 1) {
        solve(n);
    } else {
        int total_xor = 0;
        for (auto el : a) total_xor ^= el;
        if (total_xor != 0) {
            cout << "NO\n";
        } else {
            solve(n - 1);
        }
    }
}