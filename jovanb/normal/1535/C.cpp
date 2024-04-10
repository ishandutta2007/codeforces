#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int ima[2][2];

void solve(){
    string s;
    cin >> s;
    int j = 0;
    int n = s.size();
    ima[0][0] = ima[0][1] = ima[1][0] = ima[1][1] = 0;
    ll res = 0;
    for(int i=0; i<n; i++){
        if(s[i] == '1'){
            ima[1][i%2]++;
        }
        else if(s[i] == '0') ima[0][i%2]++;
        while((ima[0][0] > 0 && ima[0][1] > 0) || (ima[1][1] > 0 && ima[1][0] > 0) || (ima[0][1] > 0 && ima[1][1] > 0) || (ima[0][0] > 0 && ima[1][0] > 0)){
            if(s[j] == '1'){
                ima[1][j%2]--;
            }
            else if(s[j] == '0') ima[0][j%2]--;
            j++;
        }
        res += i-j+1;
    }
    cout << res << "\n";
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