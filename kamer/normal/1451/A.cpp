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
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n == 1) {
            cout << "0\n";
        } else if (n == 2) {
            cout << "1\n";
        } else if (n == 3) {
            cout << "2\n";
        } else if (n % 2 == 0) {
            cout << "2\n";
        } else {
            cout << "3\n";
        }
    }
}