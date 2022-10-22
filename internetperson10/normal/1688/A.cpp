#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        if(n == 1) {
            cout << "3\n";
            continue;
        }
        for(int i = 0; i < 31; i++) {
            if(n & (1 << i)) {
                if(min(n & (1 << i), (n ^ (1 << i)))) cout << (1 << i) << '\n';
                else cout << (1 << i) + 1 << '\n';
                break;
            }
        }
    }
}