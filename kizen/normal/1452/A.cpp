#include <bits/stdc++.h>

using namespace std;

using LL = long long;
const int MOD = (int)1e9 + 7;
const int NS = (int)23;
int T;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    while(T--){
        int x, y; cin >> x >> y;
        int mn = min(x, y);
        x -= mn, y -= mn;
        cout << mn * 2 + max(0, (max(x, y) - 1)) + max(x, y) << '\n';
    }
    return 0;
}