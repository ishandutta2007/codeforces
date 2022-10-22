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

int main(void) {
    int t;
    cin >> t;
    while (t--) {
        int x, n, m;
        cin >> x >> n >> m;
        if (m == 0) {
            cout << "NO\n";
        } else if (m == 1) {
            if (x <= 10) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        } else {
            if (x <= 20) {
                cout << "YES\n";
            } else {
                for (int i = 0; i < n; i++) {
                    x = (x / 2) + 10;
                }
                if (x <= 10 * m) {
                    cout << "YES\n";
                } else {
                    cout << "NO\n";
                }
                
            }
        }
    }
}