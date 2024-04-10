#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <utility>
using namespace std;

int main(void) {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        bool ordered = true;
        bool started = false;
        bool stopped = false;
        bool isSubarray = true;
        for (int i = 0; i < n; i++) {
            int a; cin >> a;
            if (a == i + 1) {
                if (started) stopped = true;
            } else {
                ordered = false;
                if (stopped) isSubarray = false;
                if (!started) started = true;
            }
        }

        if (ordered) cout << "0\n";
        else if (isSubarray) cout << "1\n";
        else cout << "2\n";
    }
}