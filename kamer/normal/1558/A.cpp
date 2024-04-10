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
        int a, b;
        cin >> a >> b;
        vector<bool> possib(a + b + 1, false);
        int x = (a + b) / 2;
        int y = a + b - x;

        for (int i = 0; i <= min(a, x); i++) {
            if (a - i <= y) {
                possib[x - i + a - i] = true;
            }
        }

        for (int i = 0; i <= min(y, a); i++) {
            if (a - i <= x) {
                possib[y - i + a - i] = true;
            }
        }

        int count = 0;
        for (auto possibility : possib) {
            if (possibility) count++;
        }

        cout << count << "\n";
        for (int i = 0; i <= a + b; i++) {
            if (possib[i]) cout << i << " ";
        }
        cout << "\n";
    }
}