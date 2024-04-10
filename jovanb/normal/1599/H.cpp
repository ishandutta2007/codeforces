#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using ld = long double;
 
int query(int x, int y){
    cout << "? " << x << " " << y << endl;
    int g;
    cin >> g;
    return g;
}
 
void answer(int a, int b, int c, int d){
    cout << "! " << a << " " << b << " " << c << " " << d << endl;
}
 
void solve(){
    int sm = query(1, 1);
    int MX = 1000000000;
    int l = 2, r = MX, naj = 1;
    while(l <= r){
        int mid = (l+r)/2;
        int g = query(1, mid);
        if(sm == g + mid - 1){
            naj = mid;
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    int yl = naj;
    int xl = sm - yl + 2;
    int g = query(MX, 1);
    /// g = (MX - xr) + (yl - 1)
    int xr = MX - g + yl - 1;
    g = query(1, MX);
    int yr = MX - g + xl - 1;
    answer(xl, yl, xr, yr);
}
 
 
int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;
 
    solve();
    return 0;
}