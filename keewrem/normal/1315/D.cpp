#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
ll k [200200];
map<ll,vector<ll>> m;

int main(){
    ll n,t ; cin >> n;
    for(ll i =0; i < n; i++)cin>> k[i];
    for(ll i =0; i < n; i++){
        cin>> t;
        m[k[i]].push_back(t);

    }
    ll res = 0;
    priority_queue<ll> move;
    ll ms = 0;
    for(auto boh: m){
        if(boh.second.size()+move.size()>1){
            sort(boh.second.begin(),boh.second.end());
            for(ll a: boh.second){
                ms+=a;
                move.push(a);
            }
            ms-=move.top();
            move.pop();
            res+=ms;
            m[boh.first+1].push_back(move.top());
            ms-=move.top();
            move.pop();
        }
    }
    cout << res << endl;
    return 0;
}