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
        int n;
        cin >> n;
        if (n < 100) {
            cout << n % 10 << "\n";
            continue;
        }

        int smallest_digit = 10;
        while (n > 0) {
            smallest_digit = min(smallest_digit, n % 10);
            n /= 10;
        }

        cout << smallest_digit << "\n";
    }
}