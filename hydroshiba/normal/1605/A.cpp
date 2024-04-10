#include "bits/stdc++.h"
using namespace std;

using lol = long long;
const lol num = 450283905890997363;

void solve(){
    lol a, b, c;
    cin >> a >> b >> c;

    lol val = llabs(a + c - 2 * b);
    for(lol step = num; step > 1; step /= 3LL){
        while(val >= step) val -= step;
    }

    cout << min(val, llabs(val - 3)) << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while(t--) solve();
}