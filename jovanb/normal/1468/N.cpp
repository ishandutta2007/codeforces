#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll c1,c2,c3,a1,a2,a3,a4,a5;

void solve(){
    cin >> c1 >> c2 >> c3;
    cin >> a1 >> a2 >> a3 >> a4 >> a5;

    if(a1 > c1 || a2 > c2 || a3 > c3){
        cout << "No" << endl;
        return;
    }

    ll p4 = min(c1-a1,a4);
    ll p5 = min(c2-a2,a5);

    ll z = a3+a4+a5-p4-p5;

    if(z >= 0 && z <= c3){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}