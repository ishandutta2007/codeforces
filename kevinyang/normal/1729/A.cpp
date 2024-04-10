#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        int a, b, c; cin >> a >> b >> c;
        int t1 = a;
        int t2 = c + abs(c-b);
        if (t1 == t2) cout << 3 << '\n';
        else if (t2 < t1) cout << 2 << '\n';
        else cout << 1 << '\n';
    }
}