#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve(){
    int n;
    cin >> n;
    int h = 1;
    int last = 2;
    for(int i=1; i<=n; i++){
        int x;
        cin >> x;
        if(h == -1) continue;
        if(last == 0 && x == 0) h = -1;
        else if(last != 1 && x) h++;
        else if(last == 1 && x) h += 5;
        last = x;
    }
    cout << h << "\n";
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