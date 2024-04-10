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

ll n, d, m, a[maxn], ps[maxn], s, x, ans, c;

int main(){
    fast_io;

    cin >> n >> d >> m;
    for(ll i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] <= m) x += a[i];
        else c++;
    }
    sort(a, a + n);
    for(ll i = 0; i <= n; i++){
        ps[i + 1] = ps[i] + a[i];
    }
    sort(a, a + n, greater<ll>());
    ans = x;
    for(ll i = 1; d * i - d + i <= n; i++){
        if(a[i - 1] <= m) continue;
        s += a[i - 1];
        if(i + d * i < c) continue;
        ll y = max(0ll, i * d + i - d - c);
        ans = max(ans, s + x - ps[y]);
    }
    cout << ans;

    return 0;
}