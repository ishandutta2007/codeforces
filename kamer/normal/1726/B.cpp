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
        int n, m;
        cin >> n >> m;
        if (m < n) {
            cout << "No\n";
            continue;
        }

        if (n % 2 == 0 && m % 2 == 1) {
            cout << "No\n";
            continue;
        }

        cout << "Yes\n";

        if (n % 2 == 1) {
            for (int i = 1; i <= n - 1; i++) {
                cout << "1 ";
            }

            cout << m - n + 1 << "\n";
        } else {
            for (int i = 1; i <= n - 2; i++) {
                cout << "1 ";
            }

            cout << (m - n + 2) / 2 << " " << (m - n + 2) / 2 << "\n";
        }
    }
}