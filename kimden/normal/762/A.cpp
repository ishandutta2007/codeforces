#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

//const ld eps = 1e-8;
//const ll mod = 1000000007;
//const int MAXN = 100002;



int main() {
    ios_base::sync_with_stdio(false);
    ll n, k;
    cin >> n >> k;
    ll cnt = 0;
    vector<ll> v;
    for(ll i = 1; i * i <= n; i++){
        if(n % i == 0){
            v.push_back(i);
            cnt++;
            if(k == cnt){
                cout << v.back() << endl;
                return 0;
            }
        }
    }
    ll mx = v.size() * 2;
    if(v.back() * v.back() == n){
        mx--;
    }
    if(k > mx){
        cout << -1 << endl;
        return 0;
    }
    v[k - 1] == n / v[n - k];
    cout << n / v[mx - k] << endl;



    return 0;
}