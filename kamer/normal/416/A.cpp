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
    int n;
    cin >> n;
    ll lower = -1500000000;
    ll upper = 1500000000;
    for (int i = 0; i < n; i++) {
        string s; ll y; char c;
        cin >> s >> y >> c;
        if (s.length() == 1) {
            if (s == ">") {
                if (c == 'Y') {
                    lower = max(lower, y + 1);
                } else {
                    upper = min(upper, y);
                }
            } else {
                if (c == 'Y') {
                    upper = min(upper, y - 1);
                } else {
                    lower = max(lower, y);
                }
            }
        } else {
            if (s == ">=") {
                if (c == 'Y') {
                    lower = max(lower, y);
                } else {
                    upper = min(upper, y - 1);
                }
            } else {
                if (c == 'Y') {
                    upper = min(upper, y);
                } else {
                    lower = max(lower, y + 1);
                }
            }
        }
    }

    if (upper < lower) {
        cout << "Impossible\n";
    } else {
        cout << upper << "\n";
    }
}