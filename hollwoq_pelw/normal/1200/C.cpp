#include <bits/stdc++.h>
using namespace std;
int main(){
    long long m,n,g;
    int q;
    cin >> n >> m >> q;
    g = __gcd(n,m);
    m /= g;
    n /= g;
    long long sx,sy,ex,ey,ps,pe;
    while(q--){
        cin >> sx >> sy >> ex >> ey;
        if (sx == 1) ps = (sy-1)/n;
        if (sx == 2) ps = (sy-1)/m;
        if (ex == 1) pe = (ey-1)/n;
        if (ex == 2) pe = (ey-1)/m;
        //cout << ps << ' ' << pe << endl;
        if (ps == pe) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}