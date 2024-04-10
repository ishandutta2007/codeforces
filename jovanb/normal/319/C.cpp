#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

ll a[100005];
ll b[100005];
ll dp[100005];

deque <pair <ll, ll>> q;

ld presek(ll k1, ll n1, ll k2, ll n2){
    return 1.0*(n2-n1)/(k1-k2);
}

void add(ll k, ll n){
    while(q.size() > 1){
        pair <ll, ll> par = q.back();
        q.pop_back();
        ll k1 = par.first, n1 = par.second;
        par = q.back();
        ll k2 = par.first, n2 = par.second;
        if(presek(k1, n1, k2, n2) < presek(k2, n2, k, n)){
            q.push_back({k1, n1});
            break;
        }
    }
    q.push_back({k, n});
}

ll resi(ll x){
    while(q.size() > 1){
        pair <ll, ll> par = q.front();
        q.pop_front();
        ll k1 = par.first, n1 = par.second;
        par = q.front();
        ll k2 = par.first, n2 = par.second;
        if(k1*x+n1 <= k2*x+n2){
            q.push_front({k1, n1});
            break;
        }
    }
    ll k = q.front().first;
    ll n = q.front().second;
    return k*x+n;
}

int main(){

    int n;
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<=n; i++) cin >> b[i];
    q.push_back({b[1], 0});
    for(int i=2; i<=n; i++){
        dp[i] = resi(a[i]);
        add(b[i], dp[i]);
    }
    cout << dp[n];
    return 0;
}