#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pld = pair<ld, ld>;



int main() {
    int n;
    cin >> n;
    int x;
    int ans = 0;
    int pol = 0;
    for(int i = 0; i < n; ++i){
        cin >> x;
        if(pol == 0 && x < 0){
            ++ans;
        }else{
            pol += x;
        }
    }
    cout << ans << endl;
}