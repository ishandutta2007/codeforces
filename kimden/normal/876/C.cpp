#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;



int main() {
    ios_base::sync_with_stdio(false);
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    ll n;
    cin >> n;
    vector<ll> o;
    for(ll i = n - 83; i <= n; ++i){
        ll sum = 0;
        ll cur = i;
        while(cur){
            sum += cur % 10;
            cur /= 10;
        }
        if(i + sum == n){
            o.push_back(i);
        }
    }
    cout << o.size() << endl;
    for(int i = 0; i < o.size(); ++i){
        cout << o[i] << endl;
    }


}