#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        if(max(n, m) == 1) cout << 0 << '\n';
        else if(min(n, m) == 1) cout << 1 << '\n';
        else cout << 2 << '\n';
    }


}