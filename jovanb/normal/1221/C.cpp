#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void solve(){
    int a, b, c;
    cin >> a >> b >> c;
    int res = min(min(a, b), c);
    a -= res;
    b -= res;
    c -= res;
    if(c == 0){
        if(a < b) swap(a, b);
        int k = min(b, a-b);
        res += k;
        b -= k;
        a -= 2*k;
        k = b/3;
        res += 2*k;
        a -= 3*k;
        b -= 3*k;
        if(a >= 2 && b >= 1) res++;
    }
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