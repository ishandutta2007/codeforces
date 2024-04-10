#include <iostream>
using namespace std;

int main(void) {
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        cout << (n * m + 1) / 2 << "\n";
    }
}