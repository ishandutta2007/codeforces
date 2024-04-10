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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (n <= 2) {
        cout << n << "\n";
        return 0;
    }

    unordered_set<int> possibs;
    possibs.insert(-1);
    int last_val = a[0];

    int res = 1;
    for (int i = 1; i < n; i++) {
        if (last_val == a[i]) {
            if (possibs.size() == 1 && possibs.find(a[i]) != possibs.end()) {
                // do nothing
            } else {
                possibs = unordered_set<int>();
                possibs.insert(a[i]);
                res++;
            }
        } else {
            res++;
            if (possibs.size() == 1 && possibs.find(a[i]) != possibs.end()) {
                // do nothings
            } else {
                possibs.insert(last_val);
            }
            last_val = a[i];
        }
    }

    cout << res << "\n";
}