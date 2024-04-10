#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);
    cout.precision(10);
    cout<<fixed;

    ll x,y;
    cin >> x >> y;
    if(y == 0){cout << "No"; return 0;}
    if(y == 1){
        if(x > 0) cout << "No";
        else cout << "Yes";
        return 0;
    }
    x -= y-1;
    if(x < 0){cout << "No"; return 0;}
    if(x % 2 == 0) cout << "Yes";
    else cout << "No";
    return 0;
}