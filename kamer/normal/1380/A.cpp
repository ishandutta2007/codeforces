#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <utility>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <string>
#include <queue>
using namespace std;
typedef long long ll;

int main(void) {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        int i1 = -1, i2 = -1, i3 = -1;
        bool dec0 = true;
        bool inc0 = false;
        bool dec1 = false;
        for (int i = 0; i < n - 1; i++) {
            if (a[i + 1] > a[i]) {
                if (dec0) {
                    dec0 = false;
                    inc0 = true;
                    i1 = i;
                }
            } else {
                if (inc0) {
                    i2 = i, i3 = i + 1;
                    break;
                }
            }
        }

        if (i3 == -1) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            cout << i1 + 1 << " " << i2 + 1 << " " << i3 + 1 << "\n";
        }
    }
}