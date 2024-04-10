//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second

ll t, n, a0, a1, a2, b0, b1, b2, ans;

int main(){
    fast_io;
    
    cin >> t;
    while(t--){
        cin >> a0 >> a1 >> a2;
        cin >> b0 >> b1 >> b2;
        ll x = min(a2, b1);
        a2 -= x;
        b1 -= x;
        ans = 2 * x;
        a1 = max(0ll, a1 - b1 - b0);
        b2 = max(0ll, b2 - a2 - a0);
        ans -= 2 * min(a1, b2);
        cout << ans << '\n';
    }

    return 0;
}