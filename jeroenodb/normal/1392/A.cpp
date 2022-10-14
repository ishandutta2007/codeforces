#include <iostream>
#include <bitset>
#include <vector>
#include <tuple>
using namespace std;
#define D(a) \
    do { cout << #a ": " << (a) << ' '; } while(false)

const int mxN = 2e5+1;

int n,a[mxN]={};

int main() {
	int t;
	cin >> t;
	while(t--) {
		cin >> n;
		int cur; cin >> cur;
		bool biggest=false;
		for(int i=1;i<n;++i) {
			int tmp;
			cin >> tmp;
			if(tmp!= cur) biggest = true;
		}
		if(biggest) {
			cout << "1\n";
		} else cout << n << "\n";

	}
}