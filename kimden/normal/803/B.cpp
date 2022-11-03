#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ll n;
    cin >> n;
    vector<ll> v(n, 0), dist(n, 2 * n);
    ll x;
    for(ll i = 0; i < n; ++i){
        cin >> v[i];
    }
    ll cur = 2 * n;
    for(ll i = 0; i < n; ++i){
        ++cur;
        if(v[i] == 0){
            cur = 0;
        }
        dist[i] = min(dist[i], cur);
    }
    cur = 2 * n;
    for(ll i = n - 1; i >= 0; --i){
        ++cur;
        if(v[i] == 0){
            cur = 0;
        }
        dist[i] = min(dist[i], cur);
    }
    for(ll i = 0; i < n; ++i){
        if(i){
            cout << " ";
        }
        cout << dist[i];
    }
    cout << endl;
}