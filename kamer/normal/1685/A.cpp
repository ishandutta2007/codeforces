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
#include <fstream>
#include <cmath>
using namespace std;
typedef long long ll;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(14);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        if (n % 2 == 1) {
            cout << "NO\n";
            continue;
        }

        sort(a.begin(), a.end());

        vector<int> b(n);
        for (int i = 0; i < n / 2; i++) {
            b[2 * i] = a[i];
            b[2 * i + 1] = a[i + n / 2];
        }

        bool is_correct = true;
        for (int i = 0; i < n; i++) {
            if (!((b[i] > b[(i + n - 1) % n] && b[i] > b[(i + 1) % n]) ||
                  (b[i] < b[(i + n - 1) % n] && b[i] < b[(i + 1) % n]))) {
                is_correct = false;
                break;
            }
        }

        if (!is_correct) {
            cout <<"NO\n";
        } else {
            cout << "YES\n";
            for (auto b_el : b) cout << b_el << " ";
            cout << "\n";
        }
    }
}