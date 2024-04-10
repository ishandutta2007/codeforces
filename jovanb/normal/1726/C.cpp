#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve(){
    int n;
    int cnt = 0;
    cin >> n;
    string s;
    cin >> s;
    for(int i=1; i<2*n; i++){
        if(s[i] == ')' && s[i-1] == '(') cnt++;
    }
    cout << n - cnt + 1 << "\n";
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