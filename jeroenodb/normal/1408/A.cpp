#include <iostream>
#include <algorithm>
using namespace std;
const int mxN = 101;
void solve() {
    int a[mxN],b[mxN],c[mxN],n; cin >> n;
    for(int i=0;i<n;++i) {
        cin >> a[i];
    }
    for(int i=0;i<n;++i) {
        cin >> b[i];
    }
    for(int i=0;i<n;++i) {
        cin >> c[i];
    }
    cout << a[0] << ' ';
    int prev = a[0];
    for(int i=1;i<n-1;++i) {
        if(a[i]!=prev) {
            cout << a[i];
            prev = a[i];
        } else if(b[i]!=prev) {
            cout << b[i];
            prev = b[i];
        } else {
            cout << c[i];
            prev = c[i];
        }
        cout << ' ';
    }
    if(a[n-1]!=prev and a[n-1]!=a[0]) {
        cout << a[n-1];
    } else if(b[n-1]!=prev and b[n-1]!=a[0]) {
        cout << b[n-1];
    } else {
        cout << c[n-1];
    } cout << endl;
}
int main() {
    int t; cin >> t;
    while(t--) {
        solve();
    }
}