#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        if((n+1)/2 < k) cout << "-1\n";
        else {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if(i == j && !(i%2) && k) {
                        cout << 'R';
                        k--;
                    }
                    else cout << '.';
                }
                cout << "\n";
            }
        }
    }
}