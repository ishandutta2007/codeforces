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
        int n, k;
        cin >> n >> k;
        vector<int> x(n), y(n);
        for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
        int result = -1;
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (j != i) {
                    if ((max(x[i] - x[j], x[j] - x[i]) + max(y[i] - y[j], y[j] - y[i])) <= k) {
                        count++;
                    } else {
                        break;
                    }
                }
            }
            if (count == n - 1) {
                result = i;
                break;
            }
        }
        if (result == -1) {
            cout << "-1\n";
        } else {
            cout << "1\n";
        }


    }
}