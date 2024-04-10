#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){

    ll n;
    cin >> n;
    int cnt = 0;
    ll minp = n;
    for(ll i=2; i*i<=n; i++){
        if(n%i == 0){
            cnt++;
            minp = min(minp, i);
            while(n%i == 0) n /= i;
        }
    }
    if(n > 1) cnt++;
    if(cnt == 1) cout << minp;
    else cout << 1;
    return 0;
}