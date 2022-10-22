#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <string>
#include <utility>
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
        string s;
        s.resize(n);
        if (n <= 20) {
            for (int i = 0; i < n; i++) {
                s[i] = 'a' + i;
            }
            cout << s << "\n";
            continue;
        }

        // n > 20
        int k = ((n / 3) - 1) / 2;
        for (int i = 0; i < k + 1; i++) s[i] = 'a';
        for (int i = k + 1; i < 2 * k + 2; i++) s[i] = 'b';
        for (int i = 2 * k + 2; i < 3 * k + 2; i++) s[i] = 'a';
        for (int i = 3 * k + 2; i < 4 * k + 3; i++) s[i] = 'c';
        for (int i = 4 * k + 3; i < 5 * k + 3; i++) s[i] = 'b';
        for (int i = 5 * k + 3; i < 6 * k + 3; i++) s[i] = 'c';
        for (int i = 6 * k + 3; i < n; i++) s[i] = 'd' + i - 6 * k - 3;
        cout << s << "\n";
    }
}