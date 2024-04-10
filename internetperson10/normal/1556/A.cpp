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
        if((x+y)%2) {
            cout << "-1\n";
        }
        else if(x == y) {
            cout << (x != 0) << '\n';
        }
        else {
            cout << "2\n";
        }
    }
}