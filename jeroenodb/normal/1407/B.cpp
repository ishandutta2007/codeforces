#include <iostream>
#include <string>
#include <algorithm>


using namespace std;
#define D(a) \
    cout << #a ": " << (a) << ' ';
const int mxN = 1e3+1;
int n, a[mxN];

void solve() {
    cin >> n;
    int mx=0, mxi;
    for(int i=0;i<n;++i) {
        cin >> a[i];
        if(a[i]> mx) {
            mx=a[i]; mxi=i;
        }
    }
    swap(a[0],a[mxi]);
    int curgcd=a[0];
    for(int i=1;i<n;++i) {
        mx=0;
        for(int j=i;j<n;j++) {
            int tmp = __gcd(curgcd,a[j]);
            if(tmp>mx) {
                mxi=j; mx = tmp;
            }
        }
        swap(a[i],a[mxi]);
        curgcd = mx;
    }

    for(int i=0;i<n;++i) {
        cout << a[i] << ' ';
    }
    cout << '\n';
}
int main() {
	int T;
	cin >> T;
	for(int i=1;i<=T;++i) {
		solve();
	}
}