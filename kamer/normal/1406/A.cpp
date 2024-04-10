#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <string>
#include <utility>
using namespace std;

int main(void) {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<bool> s(101, false);
        vector<bool> in(n, false);
        for (int i = 0; i < n; i++) {
            if (!s[a[i]]) {
                s[a[i]] = true;
                in[i] = true;
            }
        }
        unordered_set<int> f;
        unordered_set<int> se;
        for (int i = 0; i < n; i++) {
            if (in[i]) {
                f.insert(a[i]);
            } else {
                se.insert(a[i]);
            }
        }

        int A, B;
        for (int i = 0; i <= 100; i++) {
            if (f.find(i) == f.end()) {
                A = i;
                break;
            }
        }
        for (int i = 0; i <= 100; i++) {
            if (se.find(i) == se.end()) {
                B = i;
                break;
            }
        }
        cout << A + B << "\n";
    }
}