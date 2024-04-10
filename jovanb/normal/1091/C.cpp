#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

ll n;

ll resi(ll x){
    ll res=0;
    ll kolko = n/x;
    res += kolko+(kolko-1)*kolko/2*x;
    return res;
}

vector <ll> vec;

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    cin >> n;
    for(ll i=1; i*i<=n; i++){
        if(n%i == 0){
            vec.push_back(resi(i));
            if(i != n/i) vec.push_back(resi(n/i));
        }
    }
    sort(vec.begin(), vec.end());
    for(auto c : vec) cout << c << " ";
    return 0;
}