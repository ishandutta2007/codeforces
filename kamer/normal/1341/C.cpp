#include <iostream>
#include <algorithm>
#include <string>
#include <utility>
#include <tuple>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    vector<int> pos(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
        pos[p[i]] = i;
    }
    int currMaxIndex = n;
    int currElem = 0;
    while (currMaxIndex != 0) {
        int ourPos = pos[currElem];
        for (int i = ourPos + 1; i < currMaxIndex; i++) {
            if (p[i] != (p[i - 1] + 1)) {
                cout << "No\n";
                return;
            }
        }
        currElem = p[currMaxIndex - 1] + 1;
        currMaxIndex = ourPos;
    }
    cout << "Yes\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}