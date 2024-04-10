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

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(14);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> nim(n + m, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int c;
                cin >> c;
                nim[i + j] = nim[i + j] ^ c;
            }
        }
        bool nim_ok = true;
        for (int i = 0; i < n + m; i++) {
            if (nim[i]) {
                nim_ok = false;
                break;
            }
        }

        if (nim_ok) {
            cout << "Jeel\n";
        } else {
            cout << "Ashish\n";
        }
    }
}