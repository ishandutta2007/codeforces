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
        map<int, int> a;
        for (int i = 0; i < n; i++) {
            int el;
            cin >> el;
            a[el]++;
        }

        while (a.size() > 1) {
            map<int, int> a_new;
            for (auto it = a.begin(), it_next = next(it); it_next != a.end(); ++it, ++it_next) {
                int el = it_next->first - it->first;
                a_new[el]++;
            }

            for (auto it = a.begin(); it != a.end(); ++it) {
                if (it->second > 1) {
                    a_new[0] += it->second - 1;
                }
            }

            a = a_new;
        }

        if (a.begin()->second == 1) {
            cout << a.begin()->first << "\n";
        } else {
            cout << "0\n";
        }
    }
}