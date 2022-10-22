#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve(){
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    if(k == 0){
        cout << "1\n";
        return;
    }
    string t = s;
    reverse(t.begin(), t.end());
    if(t == s) cout << "1\n";
    else cout << "2\n";
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