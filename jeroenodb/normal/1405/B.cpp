#include <iostream>
#include <string>


using namespace std;
#define D(a) \
    cout << #a ": " << (a) << ' ';
const int mxN = 1e5+1;
int a[mxN];
void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    long long cost=0;
    long long ups = 0;
    long long downs=0;
    for(int i=0;i<n;++i) {
        if(a[i]<0) {
            if(ups>=-a[i]) {
                ups+=a[i];
            } else {
                cost+=-ups-a[i];
                ups=0;
            }
            
        } else if(a[i]>0) {
            ups+=a[i];
        }
    }
    cout << cost << endl;
    

}
int main() {
	int T;
	cin >> T;
	for(int i=1;i<=T;++i) {
		solve();
	}
}