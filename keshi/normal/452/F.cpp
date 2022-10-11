//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 3e5 + 100;
const ll mod = 1e9 + 1333;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second

ll n, a[maxn], f[2][maxn], p[maxn];

void upd(ll fl, ll x, ll y){
    for(x += 5; x < maxn; x += x & -x){
        f[fl][x] += y;
        if(f[fl][x] >= mod) f[fl][x] -= mod;
    }
    return;
}
ll get(ll fl, ll x){
    ll y = 0;
    for(x += 5; x > 0; x -= x & -x){
        y += f[fl][x];
        if(y >= mod) y -= mod;
    }
    return y;
}
ll sum(ll fl, ll l, ll r){
    ll x = get(fl, r) - get(fl, l - 1);
    if(x < 0) x += mod;
    return x;
}

int main(){
    fast_io;

    p[0] = 1;
    for(ll i = 1; i < maxn; i++){
        p[i] = p[i - 1] * 2;
        if(p[i] >= mod) p[i] -= mod;
    }

    cin >> n;
    for(ll i = 0; i < n; i++){
        cin >> a[i];
        a[i]--;
    }
    for(ll i = 0; i < n; i++){
        if(2 * a[i] < n){
            if((sum(0, 0, a[i] - 1) * p[n - 2 * a[i] - 1]) % mod != sum(1, a[i] + 1, 2 * a[i])){
                cout << "YES";
                return 0;
            }
        }
        else{
            if(sum(0, 2 * a[i] - n + 1, a[i] - 1) != (sum(1, a[i] + 1, n - 1) * p[2 * a[i] - n + 1]) % mod){
                cout << "YES";
                return 0;
          }
        }
        upd(0, a[i], p[a[i]]);
        upd(1, a[i], p[n - a[i] - 1]);
    }
    cout << "NO";

    return 0;
}