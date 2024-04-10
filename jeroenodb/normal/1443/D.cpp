#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
const int mxN = 3e4+2;

int main() {
    int t; cin >> t;

    while(t--) {
        int n; cin >> n;
        int a[mxN]={};
        for(int i=0;i<n;++i) {
            cin >> a[i+1];
        }
        for(int i=0;i<n;++i) {
            a[i] = a[i+1]-a[i];
        }
        int ups = a[0];
        for(int i=1;i<n;++i) {
            if(a[i]<0) {
                ups+=a[i];
            }
        }
        if(ups<0) {
            cout << "NO" << endl;
        } else {
            cout << "YES\n";
        }

    }
    
}