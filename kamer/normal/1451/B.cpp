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
        string s;
        int n, q;
        cin >> n >> q;
        cin >> s;
        for (int i = 0; i < q; i++) {
            int l, r;
            cin >> l >> r;
            l--, r--;
            bool exists = false;
            for (int j = 0; j < l; j++) {
                if (s[j] == s[l]) exists = true;
            }
            for (int j = r + 1; j < n; j++) {
                if (s[j] == s[r]) exists = true;
            }

            if (exists) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
}