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
#include <cmath>
using namespace std;
typedef long long ll;
const double eps = 1e-6;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(14);
    int t;
    cin >> t;
    while (t--) {
        ll d, k;
        cin >> d >> k;
        ll s = (d * d) / (k * k);
        ll x = floor(sqrt(s / 2) + eps);
        ll s2 = 2 * x * x + 2 * x;
        if (s <= s2) {
            cout << "Utkarsh\n";
        } else {
            cout << "Ashish\n";
        }

    }
}