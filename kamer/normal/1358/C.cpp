#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

int main(void) {
    int t;
    cin >> t;
    while(t--) {
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        ll x = x2 - x1;
        ll y = y2 - y1;
        if (x > y) {
            swap(x, y);
        }
        ll d = y - x;
        cout << x * x + d * x + 1 << "\n";
    }
}