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

int main(void) {
    int t;
    cin >> t;
    while (t--) {
        int n, a, b, c, d;
        cin >> n >> a >> b >> c >> d;
        int x = n * (a - b);
        int y = n * (a + b);
        if (c + d < x || c - d > y) {
            cout << "No\n";
        } else {
            cout << "Yes\n";
        }
    }
}