#include <iostream>
using namespace std;

int main() {
    int a[4];
    for (int i = 0; i < 4; i++) cin >> a[i];
    if (a[0] + a[1] == a[2] + a[3] || a[0] + a[2] == a[1] + a[3] || a[0] + a[3] == a[1] + a[2] || a[0] + a[1] + a[2] == a[3] || a[0] + a[1] + a[3] == a[2] || a[0] + a[2] + a[3] == a[1] || a[1] + a[2] + a[3] == a[0]) cout << "YES" << endl;
    else cout << "NO" << endl;
}