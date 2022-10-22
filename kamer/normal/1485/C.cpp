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
const double eps = 1e-6;


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(14);
    int t;
    cin >> t;
    while (t--) {
        ll x, y;
        cin >> x >> y;
        ll thresh = sqrt(x + 1) + eps;
        bool done = false;
        if (thresh >= y) {
            cout << (y * (y - 1)) / 2 << "\n";
            continue;
        }

        ll count = ((thresh - 1) * (thresh)) / 2;
        if (done) {
            cout << count << "\n";
            continue;
        }

        for (ll j = thresh - 1; j >= 1; j--) {
            ll low = x / (j + 1) + 1;
            ll high = x / j;
            if (high <= thresh + 1) continue;
            if (low > y + 1) break;
            // cout << "T " << x << " " << y << " " << j << " " << thresh << " "<< low << " " << high << "\n";
            count += (min(high, y + 1) - max(low, thresh + 2) + 1) * j;
        }

        cout << count << "\n";

    }
}