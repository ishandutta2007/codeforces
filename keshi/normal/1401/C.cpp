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

ll t, n, a[maxn], mn;
vector<ll> b, c;

int main(){
    fast_io;

    cin >> t;
    while(t--){
        cin >> n;
        mn = inf;
        b.clear();
        c.clear();
        for(ll i = 0; i < n; i++){
            cin >> a[i];
            mn = min(mn, a[i]);
        }
        for(ll i = 0; i < n; i++){
            if(a[i] % mn == 0){
                b.pb(i);
                c.pb(a[i]);
            }
        }
        sort(c.begin(), c.end());
        for(ll i = 0; i < (ll)b.size(); i++){
            a[b[i]] = c[i];
        }
        bool ok = 1;
        for(ll i = 1; i < n; i++){
            if(a[i] < a[i - 1]) ok = 0;
        }
        cout << (ok ? "YES\n" : "NO\n");
    }

    return 0;
}