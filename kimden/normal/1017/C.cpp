#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;




int main()
{
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    ll x = 0;
    while(x * x < n){
        ++x;
    }
    vector<ll> v;
    for(ll j = 0; j < x; ++j){
        for(ll i = x - 1; i >= 0; --i){
            if(i * x + j < n){
                v.push_back(i * x + j + 1);
            }
        }
    }
    for(int i = 0; i < v.size(); ++i){
        if(i){
            cout << " ";
        }
        cout << v[i];
    }
    cout << endl;

    return 0;
}