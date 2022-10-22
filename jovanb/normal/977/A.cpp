#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);
    cout.precision(10);
    cout<<fixed;

    ll n;
    cin >> n;
    ll k;
    cin >> k;
    while(k--){
        if(n%10 == 0) n /= 10;
        else n--;
    }
    cout << n;
    return 0;
}