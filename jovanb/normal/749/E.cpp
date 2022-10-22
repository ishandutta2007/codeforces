#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

ll niz[100005];
ll bit[100005];
ll cnt[100005];

pair <ll, ll> bitget(int x){
    ll res = 0;
    ll res2 = 0;
    while(x){
        res += bit[x];
        res2 += cnt[x];
        x -= x & -x;
    }
    return {res, res2};
}

void bitadd(int x, ll val){
    while(x <= 100000){
        cnt[x]++;
        bit[x] += val;
        x += x & -x;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    ld res = 0;
    for(int i=1; i<=n; i++){
        cin >> niz[i];
        ll k = bitget(niz[i]-1).first;
        res += 1.0/2*(n-i+1)*k/(1LL*n*(n+1)/2);
        bitadd(niz[i], i);
    }
    for(int i=n; i>=1; i--){
        bit[i] = 0;
        cnt[i] = 0;
    }
    for(int i=n; i>=1; i--){
        pair <ll, ll> par = bitget(niz[i]);
        ll k = par.first;
        ll x = par.second;
        //cout << k << " " << x << endl;
        res += x-1.0/2*i*k/(1LL*n*(n+1)/2);
        bitadd(niz[i], n-i+1);
    }
    cout << res;
    return 0;
}