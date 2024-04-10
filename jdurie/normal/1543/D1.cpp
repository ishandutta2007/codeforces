#include <bits/stdc++.h>
using namespace std;

int n, k, tc, res;

int main() {
    cin >> tc; while(tc--) {
        cin >> n >> k;
        for(int i = 0; i < n; ++i) {
            cout << (max(0, i - 1) ^ i) << endl;
            cin >> res; if(res) break;
        }
    }
}