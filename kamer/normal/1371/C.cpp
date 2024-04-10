#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
using namespace std;

typedef long long ll;

int main(void) {
    int t;
    cin >> t;
    while (t--) {
        ll a, b, n, m;
        cin >> a >> b >> n >> m;
        if (m <= min(a, b) && (a + b) >= n + m) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
}