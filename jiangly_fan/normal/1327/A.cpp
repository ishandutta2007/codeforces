#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        LL n, k;
        cin >> n >> k;
        cout << ((n >= k * k and (n - k) % 2 == 0) ? "YES\n" : "NO\n");
    }
    return 0;
}