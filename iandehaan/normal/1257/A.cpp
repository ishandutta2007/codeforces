#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int cs = 0; cs < t; cs++) {
        int n, x, a, b;
        cin >> n >> x >> a >> b;
        cout << min(n-1, abs(b-a) + x)  << endl;
    }
}