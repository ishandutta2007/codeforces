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
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int count0 = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') count0++;
        }

        vector<int> swaps;
        for (int i = 0; i < n; i++) {
            if (i < count0 && s[i] == '1') {
                swaps.push_back(i);
            } else if (i >= count0 && s[i] == '0') {
                swaps.push_back(i);
            }
        }

        if (swaps.size() == 0) {
            cout << "0\n";
        } else {
            cout << "1\n";

            cout << swaps.size();
            if (swaps.size() > 0) {
                for (auto val : swaps) {
                    cout << " " <<  val + 1;
                }
                cout << "\n";
            }
        }

    }
}