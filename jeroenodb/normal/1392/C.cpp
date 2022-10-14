#include <iostream>
#include <bitset>
#include <vector>
#include <tuple>
using namespace std;
#define D(a) \
    do { cout << #a ": " << (a) << ' '; } while(false)

const int mxN = 2e5+1;

int n,a[mxN]={},b[mxN];

int main() {
	int t;
	cin >> t;
	while(t--) {
		cin >> n;
		long long ans=0;
		for(int i=0;i<n;++i) {
			cin >> a[i];
		}
		for(int i=n-2;i>=0;--i) {
			if(a[i]>a[i+1]) {
				ans+=a[i]-a[i+1];
			}
		}
		cout << ans << endl;


	}
}