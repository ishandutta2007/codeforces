#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

ll f(ll a, ll b){
    ll h = a/b;
    ll l = a%b;
    return l*(h+1)*(h+1) + (b-l)*h*h;
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n, k;
    cin >> n >> k;
    k -= n;
    ll res = 0;
    priority_queue <pair <ll, pair <int, int>>> pq;
    for(int i=1; i<=n; i++){
        ll x;
        cin >> x;
        res += x*x;
        if(x > 1) pq.push({f(x, 1) - f(x, 2), {x, 2}});
    }
    while(!pq.empty() && k--){
        pair <ll, pair <int, int>> g = pq.top();
        pq.pop();
        res -= g.first;
        pair <int, int> t = g.second;
        if(t.first == t.second) continue;
        pq.push({f(t.first, t.second) - f(t.first, t.second+1), {t.first, t.second+1}});
    }
    cout << res;
    return 0;
}