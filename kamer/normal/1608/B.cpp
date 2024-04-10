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
        int n, a, b;
        cin >> n >> a >> b;
        if (a - b > 1 || b - a > 1) {
            cout << "-1\n";
            continue;
        }

        if (a + b > n - 2) {
            cout << "-1\n";
            continue;
        }

        if (a == b) {
            for (int i = 0; i < a; i++) {
                cout << i + 1 << " " << n - i << " ";
            }

            for (int i = 0; i < n - 2 * a; i++) {
                cout << i + a + 1 << " ";
            }

            cout << "\n";
        } else if (a == b + 1) {
            for (int i = 0; i < a; i++) {
                cout << i + 1 << " " << n - i << " ";
            }

            for (int i = 0; i < n - 2 * a; i++) {
                cout << n - a - i << " ";
            }

            cout << "\n";
        } else {
            for (int i = 0; i < b; i++) {
                cout << n - i << " " << i + 1 << " ";
            }

            for (int i = 0; i < n - 2 * b; i++) {
                cout << b + i + 1 << " ";
            }

            cout << "\n";
        }
    }
}