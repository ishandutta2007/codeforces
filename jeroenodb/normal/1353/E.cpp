#include <array>
#include <iostream>
#include <bitset>
#include <string>
#include <cstring>
 
using namespace std;
int r[1000000],zeroes[1000000],ones[1000000],full[1000000];
void solve() {
    int n,k;
    cin >> n >> k;

    //memset(garl,0,sizeof(int)*k);
    memset(r,-1,sizeof(int)*k);
    int total=0;
    for(int i=0;i<n;i++) {
        char c;
        cin >> c;
        if(c=='1') {
            total++;
            int mod = i%k;
            int div = i/k;
            if(r[mod]==-1) {
                r[mod] = div;
                zeroes[mod] = 1;
                ones[mod] = 0;
                full[mod] = 0;
            } else {
                int nzeroes = div-r[mod]-1;
                //cout << "nzeroes " << nzeroes << endl;
                ones[mod] = min(zeroes[mod],ones[mod]+nzeroes);
                full[mod] = min(full[mod]+1,ones[mod]);
                zeroes[mod]++;
            }
            //cout << mod << " ones " << ones[mod] << " zeroes " << zeroes[mod] << " full " << full[mod] << endl;
            r[mod]=div;
        }
    }
    if(total==0) {cout << 0 << '\n'; return;}
    int minimum=total-1;
    for(int i=0;i<k;i++) {
        if(r[i] != -1) minimum = min(total-zeroes[i]+full[i],minimum);
    }

    cout << minimum << endl;  
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}