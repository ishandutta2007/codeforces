#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
const int mxN = 1e5+1;
void solve() {
    int a, b, c; cin >> a >> b >> c;
    long long dif = a-c;
    cout << (int)ceil(sqrt((long long)b*b + dif*dif)) << endl;

}
int main() {
    int t; cin >> t;
    while(t--) {
        solve();
    }
}