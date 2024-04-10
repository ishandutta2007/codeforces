#include <bits/stdc++.h>
using namespace std;
void solve(){
    long long z,n,o;
    cin >> n >> o;
    z = n - o;
    long long base = z/(o+1);
    long long ans = base*(base+1)/2*(o+1) + (z%(o+1))*(base+1);
    cout << n*(n+1)/2-ans << endl;
    
}
int main(){
    int t;cin >> t;
    while(t--){
        solve();
    }
}