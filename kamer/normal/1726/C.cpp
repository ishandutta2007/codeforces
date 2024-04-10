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
        string s;
        cin >> s;

        vector<int> weights;
        int curr_weight = 0;
        for (char c : s) {
            if (c == '(') {
                curr_weight++;
                weights.push_back(curr_weight);
            } else {
                curr_weight--;
            }
        }

        curr_weight = -1;
        int num_comp = 0;
        for (int i = 0; i < n; i++) {
            if (weights[i] > curr_weight) {
                num_comp++;
            }
            curr_weight = weights[i];
        }

        cout << num_comp << "\n";
    }
}