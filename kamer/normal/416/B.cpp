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
    int m, n;
    cin >> m >> n;
    vector<vector<int>> t(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> t[i][j];
        }
    }

    vector<int> times(m, 0);
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < m; i++) {
            if (i == 0) times[i] += t[i][j];
            else times[i] = max(times[i], times[i - 1]) + t[i][j];
        }
    }

    for (int i = 0; i < m; i++) cout << times[i] << " " ;
    cout << "\n";
}