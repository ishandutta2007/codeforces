#include <iostream>
#include <algorithm>
#include <utility>
#include <tuple>
#include <string>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
using namespace std;
typedef long long ll;

int main(void) {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> p(2 * n);
        vector<bool> seen(2 * n, false);
        vector<int> pInd(2 * n);
        for (int i = 0; i < 2 * n; i++) {
            cin >> p[i];
            p[i]--;
            pInd[p[i]] = i;
        }

        int currentPos = 2 * n;
        int currentMax = 2 * n - 1;
        vector<int> slices;
        while (currentPos > 0) {
            //cout << currentPos << " " << currentMax << "\n";
            slices.push_back(currentPos - pInd[currentMax]);
            for (int i = pInd[currentMax]; i < currentPos; i++) {
                seen[p[i]] = true;
            }
            currentPos = pInd[currentMax];
            while (currentMax >= 0 && seen[currentMax]) currentMax--;
        }

        vector<bool> possible(n + 1, false);
        possible[0] = true;
        for (auto slice : slices) {
            //cout << slice << "\n";
            for (int i = n; i >= 0; i--) {
                if (possible[i] && (i + slice <= n)) possible[i + slice] = true;
            }
        }

        if (possible[n]) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}