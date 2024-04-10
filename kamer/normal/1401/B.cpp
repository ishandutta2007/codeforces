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
        int x[3], y[3];
        cin >> x[0] >> x[1] >> x[2] >> y[0] >> y[1] >> y[2];
        int cost = 0;
        int m = min(x[2], y[1]);
        cost += m * 2;
        x[2] -= m;
        y[1] -= m;
        
        m = min(y[2], x[0]);
        y[2] -= m;
        m = min(y[2], x[2]);
        y[2] -= m;
        cost -= y[2] * 2;

        cout << cost << "\n";
    }
}