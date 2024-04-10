#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);
    cout.precision(10);
    cout<<fixed;

    ll n, m, k;
    cin >> n >> m >> k;
    ll l=1, r=1000000000000000000;
    ll mid;
    while(l <= r){
        mid = (l+r)/2;
        ll uk = 0;
        for(int i=1; i<=n; i++){
            uk += min(m, (mid-1)/i);
        }
        if(uk >= k){
            r = mid-1;
        }
        else {
            l = mid+1;
        }
    }
    cout << l-1;
    return 0;
}