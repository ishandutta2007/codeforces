#include <bits/stdc++.h>
using namespace std;

void solve(){
    long long n, m, k;
    long long po = 0, qo = 0, pe = 0, qe = 0;
    cin >> n;
    while(n--){
        cin >> k;
        if (k%2) pe++;
        else po++;
    }
    cin >> m;
    while(m--){
        cin >> k;
        if (k%2) qe++;
        else qo++;
    }
    cout << po*qo+pe*qe << endl;
}

int main(){
    int t;cin >> t;
    while(t--) solve();
    return 0;
}