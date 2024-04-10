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
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        bool wannaStart = true;
        for (int i = n - 2; i >= 0; i--) {
            if (wannaStart) {
                if (a[i] == 1) {
                    wannaStart = false;
                } else {
                    wannaStart = true;
                }
            } else {
                wannaStart = true;
            }
        }

        if (wannaStart) {
            cout << "First\n";
        } else {
            cout << "Second\n";
        }
    }
}