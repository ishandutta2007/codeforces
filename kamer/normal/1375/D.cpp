#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <set>
#include <unordered_set>
#include <tuple>
#include <map>
#include <unordered_map>
#include <queue>
using namespace std;
typedef long long ll;

bool checkSorted(vector<int>& a) {
    for (int i = 0; i + 1 < a.size(); i++) {
        if (a[i] > a[i + 1]) return false;
    }
    return true;
}

int findMEX(vector<int>& a) {
    int n = a.size();
    vector<int> count(n + 1, 0);
    for (auto x : a) count[x]++;
    for (int i = 0; i <= n; i++) {
        if (count[i] == 0) return i;
    }
    return -1;
}

int main(void) {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> ops;
        for (int i = 0; i < n; i++) cin >> a[i];
        if (checkSorted(a)) {
            cout << "0\n\n";
            continue;
        }

        while (true) {
            for (auto ax : a) {
              //  cout << ax << " ";
            }
            // cout << endl;
            int mex = findMEX(a);
            // cout << mex << endl;
            if (mex == n) {
                for (int i = 0; i < n; i++) {
                    if (a[i] != i) {
                        a[i] = mex;
                        ops.push_back(i);
                        break;
                    }
                }
            } else {
                a[mex] = mex;
                ops.push_back(mex);
            }

            if (checkSorted(a)) {
                cout << ops.size() << "\n";
                for (auto op : ops) {
                    cout << op + 1 << " ";
                }
                cout << "\n";
                break;
            }
        }
    }
}