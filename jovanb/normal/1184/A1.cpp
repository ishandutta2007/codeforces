#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    ll r;
    cin >> r;
    r--;
    ll x = 1;
    while(1){
        if(x*x + x >= r) break;
        if((r-x*x-x)%(2*x) == 0){
            cout << x << " " << (r-x*x-x)/(2*x);
            return 0;
        }
        x++;
    }
    cout << "NO\n";
    return 0;
}