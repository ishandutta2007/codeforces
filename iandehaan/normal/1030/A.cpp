#include <iostream>
using namespace std;

int main() {
    int n, x;
    cin >> n;
    int sm = 0;
    for (int i = 0; i < n; i++) {
        cin >> x;
        sm += x;
    }
    if (sm) cout  << "HARD" << endl;
    else cout << "EASY" << endl;
}