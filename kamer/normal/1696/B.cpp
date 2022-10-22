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
        int count_zero = 0;
        bool inside = false;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            if (a != 0) {
                if (!inside) {
                    inside = true;
                    count_zero++;
                }
            } else {
                inside = false;
            }
        }

        cout << min(count_zero ,2) << "\n";
    }
}