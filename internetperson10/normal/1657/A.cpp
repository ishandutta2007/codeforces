#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int x, y;
        cin >> x >> y;
        if(x + y == 0) {
            cout << "0\n";
            continue;
        }
        for(int i = 0; i <= 100; i++) {
            if(x * x + y * y == i * i) {
                cout << "1\n";
                break;
            }
            if(i == 100) {
                cout << "2\n";
            }
        }
    }
}