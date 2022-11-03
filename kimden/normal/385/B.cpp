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
    string s;
    cin >> s;
    if(s.length() < 4){
        cout << 0 << endl;
        return 0;
    }
    ll ans = 0;
    ll mx = 0;
    for(int i = 0; i < s.length() - 3; ++i){
        if(s[i] == 'b' && s[i + 1] == 'e' && s[i + 2] == 'a' && s[i + 3] == 'r'){
            ans += (i + 1 - mx) * ll(s.length() - i - 3);
            mx = i + 1;
        }
    }
    cout << ans << endl;
}