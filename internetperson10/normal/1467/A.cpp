#include <bits/stdc++.h>

using namespace std;

vector<long long int> nums;

int main() {
    int t;
    int n, k, a, b, c, d, x, y, z;
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 0; i < (int)(min(2, n)); i++) {
            cout << (9-i);
        }
        for(int i = 2; i < n; i++) {
            cout << (7+i)%10;
        }
        cout << '\n';
    }
}