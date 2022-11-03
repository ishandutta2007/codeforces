#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;



int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    string s;
    cin >> s;
    ll ans = 0;
    for(int i = 0; i < n; ++i){
        if(s[i] == '1'){
            ++ans;
        }else{
            ans *= 10;
        }
    }
    cout << ans << endl;



    return 0;
}