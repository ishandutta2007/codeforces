#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll INF = 1000000000000000000LL;

void solve(){
    int n;
    cin >> n;
    ll mx = -INF;
    vector <ll> pos, neg;
    for(int i=1; i<=n; i++){
        int x;
        cin >> x;
        if(x == 0){
            mx = 0;
        }
        if(x < 0) neg.push_back(x);
        else pos.push_back(x);
    }
    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end());
    for(int a=0; a<=5; a++){
        int b = 5-a;
        if(neg.size() < b || pos.size() < a) continue;
        ll sad = 1;
        if(b%2){
            for(int i=0; i<a; i++) sad *= pos[i];
            for(int j=0; j<b; j++) sad *= neg[neg.size()-1-j];
        }
        else{
            for(int i=0; i<a; i++) sad *= pos[pos.size()-1-i];
            for(int j=0; j<b; j++) sad *= neg[j];
        }
        mx = max(mx, sad);
    }
    cout << mx << "\n";
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}