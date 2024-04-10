#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

/*



















 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int a[2][2];
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 2; j++) {
                cin >> a[i][j];
            }
        }
        if(a[0][0] + a[0][1] + a[1][0] + a[1][1] == 4) {
            cout << "2\n";
        }
        else if(a[0][0] + a[0][1] + a[1][0] + a[1][1]) {
            cout << "1\n";
        }
        else {
            cout << "0\n";
        }
    }
}