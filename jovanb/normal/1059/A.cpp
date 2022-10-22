#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n, l, a;
    cin >> n >> l >> a;
    int res=0;
    int pr=0;
    for(int i=1; i<=n; i++){
        int x, y;
        cin >> x >> y;
        res += (x-pr)/a;
        pr = x+y;
    }
    res += (l-pr)/a;
    cout << res;
    return 0;
}