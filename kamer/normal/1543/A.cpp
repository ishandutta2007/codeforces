#include <iostream>
using namespace std;
typedef long long ll;

int main(void) {
    int t;
    cin >> t; 
    while (t--) {
        ll a, b;
        cin >> a >> b;
        if (a == b) {
            cout << "0 0\n";
            continue;
        }

        ll d = max(a - b, b - a);
        cout << d << " " << min(a % d, d - a % d) << "\n";
    }
}