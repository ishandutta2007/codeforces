#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
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
        ll a, b, c;
        cin >> a >> b >> c;
        if (a < c) {
            cout << "1 ";
        } else {
            cout << "-1 ";
        }

        if (a * b > c) {
            cout << b;
        } else {
            cout << "-1";
        }
        cout << "\n";
    }
}