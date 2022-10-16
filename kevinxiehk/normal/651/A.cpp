#include <bits/stdc++.h>
using namespace std;
int main() {
    int a, b;
    cin >> a >> b;
    if(a % 3 == b % 3) {
        cout << max(0, a + b - 3);
    }
    else cout << a + b - 2;
    return 0;
}