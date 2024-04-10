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
#include <complex>
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
        vector<ll> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        ll sum = 0;
        bool negative_prefix = false;
        int first_zero = n;
        for (int i = 0; i < n; i++) {
            sum += a[i];
            if (sum < 0) {
                negative_prefix = true;
            }

            if (sum == 0) {
                first_zero = min(first_zero, i);
            }
        }

        if (first_zero == n) {
            cout << "No\n";
            continue;
        }

        if (negative_prefix) {
            cout << "No\n";
            continue;
        }

        bool suffix_zero = true;
        for (int i = first_zero + 1; i < n; i++) {
            if (a[i] != 0) {
                suffix_zero = false;
            }
        }

        if (suffix_zero) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
}