#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <string>
#include <utility>
#include <iomanip>
#include <fstream>
#include <cmath>
using namespace std;
typedef long long ll;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(14);
    int n, m;
    cin >> n >> m;

    vector<int> count(n + 1, 0);
    count[1] = 1;

    for (int i = 2; i <= n; i++) {
        int adder = 2 * count[i - 1];
        if (adder >= m) adder -= m;
        count[i] += adder;
        if (i > 2) count[i]++;
        if (count[i] >= m) count[i] -= m;


        for (int j = 2 * i; j <= n; j += i) {
            count[j] += count[i];
            if (count[j] >= m) count[j] -= m;
            count[j] -= count[i - 1];
            if (count[j] < 0) count[j] += m;
        }
    }

    cout << count[n] << "\n";
}