#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(false);
    int n, d;
    cin >> n >> d;
    ll ans = 0;
    ll jok = 0;
    ll x;
    for(int i = 0; i < n; ++i){
        cin >> x;
        ans += x;
        if(i){
            ans += 10;
            jok += 2;
        }
    }
    if(ans > d){
        cout << "-1\n";
    }else{
        cout << jok + (d - ans) / 5 << endl;
    }
}