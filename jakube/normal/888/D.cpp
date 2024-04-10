#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, k;
    cin >> n >> k;
    if (k == 1) {
        cout << 1 << endl;
    } else if (k == 2) {
        cout << (n*(n-1)/2) + 1 << endl;
    } else if (k == 3) {
        cout << (n*(n-1)*(n-2)/3) + (n*(n-1)/2) + 1 << endl;
    } else if (k == 4) {
        cout << (n*(n-1)*(n-2)*(n-3)/4/3/2*9)   +(n*(n-1)*(n-2)/3) + (n*(n-1)/2) + 1 << endl;
    }
}