#include <algorithm>
#include <array>
#include <iostream>
 
using namespace std;
const int MOD = 1000000007;
int main() {
    int n,k,d;
    cin >> n >> k >> d;
    array<int,101> with={},without = {};
    without[0] = 1;
    for(int i=0;i<=n;i++) {
        if(without[i]!=0) {
            for(int j=1; j<=n-i && j<d;j++) {
                //cout << "Picking small " << j << " from small i " << i << endl;
                without[i+j] = (without[i+j]+without[i])%MOD;
            }
            for(int j=d; j<=n-i && j<=k;j++) {
                //cout << "Picking big " << j << " from small i " << i << endl;
                with[i+j] = (with[i+j]+without[i])%MOD;
            }
        } 
        if(with[i]!=0) {
            for(int j=1; j<=n-i && j<=k;j++) {
                //cout << "Picking big " << j << " from big i " << i << endl;
                with[i+j] = (with[i+j]+with[i])%MOD;
            }
        }
    }
    cout << with[n] << endl;
}