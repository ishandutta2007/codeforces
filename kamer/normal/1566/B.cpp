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
        string s;
        cin >> s;
        int n = s.length();
        int count0 = 0, count1 = 0;
        bool first_zero = false, reading_zero = false, bad_zero = false;
        for (auto c : s) {
            if (c == '0') {
                count0++;
                if (first_zero && !reading_zero) {
                    bad_zero = true;
                }
                first_zero = true;
                reading_zero = true;
            } else {
                count1++;
                reading_zero = false;
            }
        }

        if (count0 == 0) {
            cout << "0\n";
        } else if (count1 == 0) {
            cout << "1\n";
        } else if (!bad_zero) {
            cout << "1\n";
        } else {
            cout << "2\n";
        }
    }
}