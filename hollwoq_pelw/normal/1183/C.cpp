#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        long long n,k,a,b;
        cin >> k >> n >> a >> b;
        k -= b*n;
        if (k <= 0) cout << -1 << endl;
        else cout << min(n,(k-1)/(a-b)) << endl;
    }
    return 0;
}