#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <utility>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <string>
#include <queue>
using namespace std;
typedef long long ll;

int main(void) {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        vector<int> b(n);
        for (int i = 0; i < n; i++) {
            b[i] = (x + a[i] - 1) / a[i];
        }

        int lastPos = n;
        int numTeams = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (b[i] <= lastPos - i) {
                numTeams++, lastPos = i;
            }
        }

        cout << numTeams << "\n";
    }
}