#include <iostream>
#include <string>
#include <algorithm>


using namespace std;
#define D(a) \
    do { cout << #a " " << (a) << std::endl; } while(false)
const int mxN=1e5;
void solve() {
    int n;
    cin >> n;
    int a[mxN];
    for(int i=0;i<n;++i) {
        cin >> a[i];
    }
    sort(a,a+n);
    //for(int i=0;i<n;++i) cout << a[i] << endl;
    long long cost1 = 0;
    for(int i=0;i<n;++i) {
            cost1+=abs(a[i]-1);
    }
        
    if(n>40) {
        cout << cost1 << endl; return;
    }
    long long best=cost1;
    for(int i=2;;++i) {
        //D(i);
        bool cant = false;
        long long power=1;
        long long curcost=0;
        for(int j=0;j<n;++j) {
            curcost+=abs(a[j]-power);
            //D(curcost);
            if(power>(long long)1e10*n) {
                cant=true;break;
            }
            power*=i;

        }
        best = min(best,curcost);
        if(cant) break;
    }
    cout << best << endl;


    

}
int main() {
	solve();
}