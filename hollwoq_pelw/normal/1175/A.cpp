#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        long long n,k,ans=0;
        cin >> n >> k;
        while(n){
            if (n%k) {ans += n%k; n -= n%k;}
            else {ans ++; n /= k;}
        }
        cout << ans << endl;
    }
    return 0;
}