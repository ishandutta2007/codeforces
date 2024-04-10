#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
const int mxN = 1e5+3;
void solve() {
    int a[mxN],n,l; cin >> n >> l;
    int different = 1;
    a[0]=0;
    for(int i=1;i<=n;++i) {
        cin >> a[i];
    }
    a[n+1]=l;
    double times[mxN][2]={};
    int speed = 1;
    double prevtime = 0;
    for(int i=1;i<=n+1;++i) {
        times[i][0] = times[i-1][0]+(double)(a[i]-a[i-1])/speed;
        speed++;
    }
    speed = 1;
    for(int i=n;i>=0;--i) {
        times[i][1] = times[i+1][1]+(double)(a[i+1]-a[i])/speed;
        speed++;
    }
    int cross=0;
    while(times[cross][0] < times[cross][1]) cross++;
    int v1 = cross, v2 = n-cross+2;
    double t = a[cross] - a[cross-1] + v1*times[cross-1][0] + v2*times[cross][1];
    t/=v1+v2;
    cout << setprecision(10) << t << endl;
    

}
int main() {
    int t; cin >> t;
    while(t--) {
        solve();
    }
}