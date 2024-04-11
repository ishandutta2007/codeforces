#include <iostream>
 
using namespace std;
 
int x[3], y[3];
 
bool is_between(int a, int b, int c) {
    return min(a, b) <= c && c <= max(a, b);
}
 
bool f(int i, int j, int k) {
    return (x[k] == x[i] || x[k] == x[j]) && is_between(y[i], y[j], y[k]) ||
           (y[k] == y[i] || y[k] == y[j]) && is_between(x[i], x[j], x[k]);
}
 
int main() {
    for (int i = 0; i < 3; i++) {
        cin >> x[i] >> y[i];
    }
 
    if (x[0] == x[1] && x[1] == x[2] || y[0] == y[1] && y[1] == y[2]) {
        cout << "1\n";
    } else if (f(0, 1, 2) || f(0, 2, 1) || f(1, 2, 0)) {
        cout << "2\n";
    } else {
        cout << "3\n";
    }
}