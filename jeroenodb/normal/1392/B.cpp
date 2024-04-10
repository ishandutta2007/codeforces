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
		long long k;
		cin >> n >> k;
		int mn=2e9,mx=-2e9;
		for(int i=0;i<n;++i) {
			cin >> a[i];
			mx = max(mx,a[i]);mn=min(mn,a[i]);
		}
		if(k%2==1) {
			for(int i=0;i<n;++i) {
				cout << mx-a[i] << ' ';
			}
		} else {
			for(int i=0;i<n;++i) {
				cout << -mn+a[i] << ' ';
			}
		} cout << "\n";

	}
}