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
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int max_a = -1;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            max_a = max(a, max_a);
        }

        int m;
        cin >> m;
        int max_b = -1;
        for (int i = 0; i < m; i++) {
            int b;
            cin >> b;
            max_b = max(b, max_b);
        }

        if (max_a < max_b) {
            cout << "Bob\nBob\n";
        } else if (max_a == max_b) {
            cout << "Alice\nBob\n";
        } else {
            cout << "Alice\nAlice\n";
        }
    }
}