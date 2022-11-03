#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

ll row[1000];
ll col[1000];
ll n, m;

ll fc(ll x){
    ll res = 0;
    for (ll i = 0; i < m; i++){
        res += col[i] * 1LL * (1 + 2 * i - 2 * x) * 1LL * (1 + 2 * i - 2 * x); // x4
    }
    return res;
}

ll fr(ll x){
    ll res = 0;
    for (ll i = 0; i < n; i++){
        res += row[i] * 1LL * (1 + 2 * i - 2 * x) * 1LL *  (1 + 2 * i - 2 * x); // x4
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    ll x, y;
    ll ans = 0;
    ll cur;
    ll a;
    cin >> n >> m;
    for (ll i = 0; i < n; i++){
        for(ll j = 0; j < m; j++){
            cin >> a;
            row[i] += a;
            col[j] += a;
        }
    }
    ll l, m1, m2, r;
    l = 0;
    r = m;
    while (r - l >= 3){
        m1 = l + (r - l) / 3;
        m2 = l + 2 * (r - l) / 3;
        if (fc(m1) <= fc(m2)){
            r = m2;
        } else {
            l = m1;
        }
    }
    cur = fc(l);
    x = l;
    ll tmp;
    for(ll i = l + 1; i <= r; i++){
        tmp = fc(i);
        if(tmp < cur){
            cur = tmp;
            x = i;
        }
    }
    ans += cur;

    l = 0;
    r = n;
    while (r - l >= 3){
        m1 = l + (r - l) / 3;
        m2 = l + 2 * (r - l) / 3;
        if (fr(m1) <= fr(m2)){
            r = m2;
        } else {
            l = m1;
        }
    }
    cur = fr(l);
    y = l;
    for(ll i = l + 1; i <= r; i++){
        tmp = fr(i);
        if(tmp < cur){
            cur = tmp;
            y = i;
        }
    }
    ans += cur;
    cout << ans * 4 << "\n" << y << " " << x;
    return 0;
}