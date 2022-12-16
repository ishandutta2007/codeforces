#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a+n);

    uint64_t up = 0;
    uint64_t rt = 0;
    for (int i = 0; i < n/2; i++) {
        up += a[i];
    }
    for (int i = n-1; i >= n/2; i--) {
        rt += a[i];
    }

    uint64_t out = up*up + rt*rt;

    cout << out << endl;
}