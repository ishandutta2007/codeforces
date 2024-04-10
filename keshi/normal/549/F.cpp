//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 2e6 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e9;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second

ll n, k, a[maxn], b[maxn], c[maxn], ans, cnt[maxn];

void solve(ll s, ll e){
    if(e - s == 1) return;
    ll mid = (s + e) >> 1;
    ll p = mid - 1;
    ll y = 0, mx = 0;
    for(ll i = mid; i < e; i++){
        y += c[i];
        if(y >= k) y -= k;
        b[i] = y;
    }
    y = 0;
    for(ll i = mid - 1; i >= s; i--){
        y += c[i];
        if(y >= k) y -= k;
        b[i] = y;
    }
    for(ll i = mid; i < e; i++){
        mx = max(mx, a[i]);
        while(p >= s && a[p] <= mx){
            cnt[b[p--]]++;
        }
        ans += cnt[(mx - b[i] + k) % k];
    }
    for(ll i = mid - 1; i >= s; i--){
        cnt[b[i]] = 0;
    }
    mx = 0;
    p = mid;
    for(ll i = mid - 1; i >= s; i--){
        mx = max(mx, a[i]);
        while(p < e && a[p] < mx){
            cnt[b[p++]]++;
        }
        ans += cnt[(mx - b[i] + k) % k];
    }
    for(ll i = mid; i < e; i++){
        cnt[b[i]] = 0;
    }
    solve(s, mid);
    solve(mid, e);
    return;
}

int main(){
    fast_io;

    cin >> n >> k;
    for(ll i = 0; i < n; i++){
        cin >> a[i];
        c[i] = a[i] % k;
    }
    solve(0, n);
    cout << ans;

    return 0;
}