#include <iostream>
#include <bitset>
#include <vector>
#include <tuple>
using namespace std;
#define D(a) \
    do { cout << #a ": " << (a) << ' '; } while(false)

const int mxN = 2e5+1;

int n;

int main() {
	cin >> n;
	for(int x=0;x<n;++x) {
		if(x%2==0) {
			for(int i=0;i<n;++i) cout << "0 ";
		} else {
			for(int i=0;i<n;++i) cout << (1LL<<(x+i-1))<<' ';
		} cout << endl;

	}
	int q; cin >> q;
	while(q--) {
		long long k;
		cin >> k;
		vector<pair<int,int>> ans;
		bool na=false;
		int y=0,x=-1;
		for(int i=0;i<2*n;++i) {
			if((1LL<<i) & k) {
				//cout << "through " << (1LL<<i) << endl;
				if(na==false) {
					//cout << "row down " << endl;
					++x;
					for(;y<=i-x;++y) {
						ans.push_back({x,y});
					}
					ans.push_back({++x,--y});
				} else {
					ans.push_back({x,++y});
				}
				na=true;
			} else {
				na=false;
			}
		}
		++x;
		if(x<n) {
			for(;y<n;++y) {
				ans.push_back({x,y});
			}
		}
		for(auto p:ans) {
			cout << p.first+1 << ' ' << p.second+1 << endl;
		}
	}
}