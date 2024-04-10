#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void solve(){
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    a /= 2;
    int res = 0;
    if(d < e){
        swap(d, e);
        swap(b, c);
    }
    res += d*min(a, b);
    a -= min(a, b);
    res += e*min(a, c);
    cout << res << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}