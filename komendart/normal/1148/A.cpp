#include <bits/stdc++.h>

using namespace std;

#define int long long
#define sz(x) ((int) (x).size())

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    int a, b, c;
    cin >> a >> b >> c;
    
    a = min(a, b + 1);
    b = min(b, a + 1);
    
    cout << 2 * c + a + b << endl;
}