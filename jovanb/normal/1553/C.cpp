#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int opt[2][2];

void solve(){
    string s;
    cin >> s;
    int n = s.size();
    opt[1][0] = opt[1][1] = opt[0][0] = opt[0][1] = 0;
    int turns0 = 5, turns1 = 5;
    for(int i=0; i<n; i++){
        int k = i%2;
        if(k%2) turns1--;
        else turns0--;
        if(s[i] == '1'){
            opt[0][k]++;
            opt[1][k]++;
        }
        else if(s[i] == '?'){
            opt[k][k]++;
        }
        if(opt[0][0] - opt[0][1] > turns1){
            cout << i+1 << "\n";
            return;
        }
        if(opt[1][1] - opt[1][0] > turns0){
            cout << i+1 << "\n";
            return;
        }
    }
    cout << "10\n";
    return;
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