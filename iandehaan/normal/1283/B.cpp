#include <iostream>
using namespace std;

int main() {
    int t, n, k;;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        cout << min(n, k/2 + (n/k)*k) << endl;
    }
}