#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <tuple>
#include <utility>
#include <queue>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
using namespace std;
typedef long long ll;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        ll n, l, r;
        cin >> n >> l >> r;
        l--, r--;
        if (n == 2) {
            vector<int> a(3);
            a[0] = 1, a[1] = 2, a[2] = 1;
            for (int i = l; i <= r; i++) {
                cout << a[i] << " ";
            }
            cout << "\n";
            continue;
        }

        ll realL = l, realR = r;
        if (realL == n * (n - 1)) {
            cout << "1\n";
            continue;
        }

        ll leftBegin = 1;
        ll index = 0;
        while (index + 2 * (n - leftBegin) <= realL) {
            index += 2 * (n - leftBegin);
            leftBegin++;
        }
        if (realR == n * (n - 1)) {
            vector<int> res;
            for (int i = leftBegin; i <= n - 1; i++) {
                for (int j = 0; j < 2 * (n - i); j++) {
                    if (j % 2 == 0) {
                        res.push_back(i);
                    } else {
                        res.push_back(i + ((j + 1) / 2));
                    }
                }
            }
            res.push_back(1);
            for (int i = realL - index; i < res.size(); i++) {
                cout << res[i] << " ";
            }
            cout << "\n";
            continue;
        }

        ll rightBegin = leftBegin;
        ll leftIndex = index;
        while (index + 2 * (n - rightBegin) <= r) {
            index += 2 * (n - rightBegin);
            rightBegin++;
        }

        vector<int> res;
        for (int i = leftBegin; i <= rightBegin; i++) {
            for (int j = 0; j < 2 * (n - i); j++) {
                if (j % 2 == 0) {
                    res.push_back(i);
                } else {
                    res.push_back(i + ((j + 1) / 2));
                }
            }
        }

        for (int i = realL - leftIndex; i <= realR - leftIndex; i++) {
            cout << res[i] << " ";
        }
        cout << "\n";
    }
}