#include <iostream>
#include <bitset>
#include <vector>
#include <tuple>
using namespace std;
#define D(a) \
    do { cout << #a ": " << (a) << ' '; } while(false)

const int mxN = 5*1e4+1;

int n,a[mxN]={};

int main() {
	int t;
	cin >> t;
	while(t--) {
		cin >> n;
		for(int i=0;i<n;++i) cin >> a[i];
		if(a[0]+a[1]<=a[n-1]) {
			cout << "1 2 " << n << '\n';
		} else {
			cout << "-1\n";
		}
	}
}