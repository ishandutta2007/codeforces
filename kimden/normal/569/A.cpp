#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;



int main() {
    ios_base::sync_with_stdio(false);
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    ll t, s, q;
    cin >> t >> s >> q;
    ll ans = 0;
    s *= q;
    while(1){
        ++ans;
        if(s >= t){
            break;
        }
        s *= q;
    }
    cout << ans << endl;
}