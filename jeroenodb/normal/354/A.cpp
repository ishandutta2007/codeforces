#include <iostream>
#include <string>


using namespace std;
#define D(a) \
    do { cout << #a " " << (a) << std::endl; } while(false)
const int mxN = 1e5+2;
int pref[mxN];
int main() {
	long long n,l,r,ql,qr;
    cin >> n >> l >> r >> ql >> qr;
    int i=0;
    pref[0]=0;
    for(int i=1;i<=n;++i) {
        cin >> pref[i];
        pref[i]+=pref[i-1];
    }
    long long best = 2e9;
    for(int i=0;i<=n;++i) {
        long long cur = l*pref[i];
        int lenl=i, lenr=n-i;
        cur+=ql*max(0,lenl-lenr-1);
        cur+=r*(pref[n]-pref[i]);
        cur+=qr*max(0,lenr-lenl-1);

        best=min(cur,best);
    }
    cout << best << endl;
}