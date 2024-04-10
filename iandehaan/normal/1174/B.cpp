#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    bool odd = false;
    bool even = false;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] % 2 == 0) {
            even = true;
        } else {
            odd = true;
        }
    }
    if (even && odd) {
        sort(a, a+n);
    }
    for (int i = 0; i < n-1; i++) {
        cout << a[i] << ' ';
    }
    cout << a[n-1] << endl;
}