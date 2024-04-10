#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int m = 1;
    int cap = 0;
    while (cap < n-1) {
        m++;
        cap += 2;
    }
    cout << m << endl;
    int posx = 1;
    int posy = 1;
    for (int i = 0; i < n; i++) {
        cout << posx << ' ' << posy << endl;
        if (posx < m) {
            posx++;
        } else {
            posy++;
        }
    }
}