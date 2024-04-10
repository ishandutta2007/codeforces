#include <iostream>
using namespace std;

int main(void) {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int countNeighbours = 0;
        for (int i = 0; i < n - 1; i++) {
            int a, b;
            cin >> a >> b;
            if (a == x || b == x) countNeighbours++;
        }
        if (n == 1 || n == 2) {
            cout << "Ayush\n";
        } else if (countNeighbours == 1) {
            cout << "Ayush\n";
        } else {
            if (n % 2 == 1) {
                cout << "Ashish\n";
            } else {
                cout << "Ayush\n";
            }
        }
    }
}