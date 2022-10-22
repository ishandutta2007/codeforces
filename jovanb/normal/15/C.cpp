#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll ksor(ll x){
    if(x%4 == 0) return x;
    if(x%4 == 1) return 1;
    if(x%4 == 2) return x+1;
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);

    int n;
    ll x = 0;
    cin >> n;
    while(n--){
        ll a, b;
        cin >> a >> b;
        x ^= (ksor(b+a-1) ^ ksor(a-1));
    }
    if(x == 0){
        cout << "bolik\n";
    }
    else cout << "tolik\n";
    return 0;
}