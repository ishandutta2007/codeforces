#include <iostream>
#include <cassert>
using namespace std;
const int mxN = 500;

int main() {
    int t; cin >> t;
    while(t--) {
        bool bad[mxN] = {};
        int n; cin >> n;
        int count = 0;
        for(int i=2*n;i<=4*n and count!=n;i+=2) {
            if(!bad[i]) {
                cout << i << ' ';
                count++;
                for(int j=2*i;j<=4*n;j+=i) {
                    bad[j] = true;
                }
            }
        } cout << endl;
        assert(count==n);

    }
    
}