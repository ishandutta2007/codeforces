#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
using namespace std;

typedef long long ll;

int main(void) {
    int t;
    cin >> t;
    while (t--) {
        ll a, b, n;
        cin >> a >> b >> n;
        ll temp;
        if (a < b) {
            temp = a;
            a = b;
            b = temp;
        }

        ll count = 0;
        while (a <= n) {
            b = a + b;
            temp = a;
            a = b;
            b = temp;
            count++;
        }
        cout << count << "\n";
    }
}