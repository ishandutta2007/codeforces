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
using namespace std;
typedef long long ll;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(14);
    int n;
    cin >> n;
    vector<int> results(n, 0);
    vector<int> vals(n, 0);
    int target1 = -1, target2 = -1;
    int target3 = -1;
    for (int i = 2; i <= n; i++) {
        cout << "XOR 1 " << i << "\n";
        cout.flush();
        int res;
        cin >> res;
        results[i - 1] = res;
        if (res == 0 && target3 == -1) {
            target3 = i;
        }
        if (vals[res] != 0 && target1 == -1) {
            target1 = vals[res];
            target2 = i;
        } else {
            vals[res] = i;
        }
    }

    if (target3 != -1) {
        cout << "AND 1 " << target3 << "\n";
        cout.flush();
        int res;
        cin >> res;
        vector<int> target(n, 0);
        target[0] = res;
        for (int i = 1; i < n; i++) {
            target[i] = res ^ results[i];
        }
        cout << "! ";
        for (auto val : target) cout << val << " ";
        cout << "\n";
        cout.flush();
    } else if (target1 != -1) {
        cout << "AND " << target1 << " " << target2 << "\n";
        cout.flush();
        int res;
        cin >> res;
        vector<int> target(n, 0);
        target[0] = res ^ results[target1 - 1];
        for (int i = 1; i < n; i++) {
            target[i] = target[0] ^ results[i];
        }
        cout << "! ";
        for (auto val : target) cout << val << " ";
        cout << "\n";
        cout.flush();
    } else {
        cout << "AND 1 " << vals[1] << "\n";
        cout.flush();
        int res1;
        cin >> res1;
        cout << "AND 1 " << vals[2] << "\n";
        cout.flush();
        int res2;
        cin >> res2;
        vector<int> target(n, 0);
        target[0] = (res1 & (-2)) | (1 & res2);
        for (int i = 1; i < n; i++) {
            target[i] = target[0] ^ results[i];
        }
        cout << "! ";
        for (auto val : target) cout << val << " ";
        cout << "\n";
        cout.flush();
    }
}