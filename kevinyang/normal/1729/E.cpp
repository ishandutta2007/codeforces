#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int cnt = 25;
    for (int n = 3; n <= 1000; ++n){
        for (int i = 1; i < n; ++i){
            int j = n - i;
            if (i >= j) break;
            if (cnt == 0) assert(0);
            cnt--;
            cout << "? " << i << " " << j << '\n';
            cout << "? " << j << " " << i << '\n';
            cout.flush();
            ll a, b; cin >> a >> b;
            if (a == -1 || b == -1){
                cout << "! " << max(i, j) - 1 << '\n';
                return 0;
            }
            if (a == b) continue;
            cout << "! " << a+b << '\n';
            return 0;
        }
    }
}