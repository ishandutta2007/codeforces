#include <iostream>
#include <string>
#include <algorithm>


using namespace std;
#define D(a) \
    do { cout << #a " " << (a) << std::endl; } while(false)
//const int mxN=1e5;
void solve() {
    int n;
    cin >> n;
    //int a[mxN];
    int mx=0,sum=0;
    for(int i=0;i<n;++i) {
        int cur; cin >> cur;
        sum+=cur; mx=max(mx,cur);
    } sum-=mx;
    if(mx>sum) {
    	puts("T");
    } else {
    	sum+=mx;
    	if(sum%2==0) {
    		puts("HL");
    	} else {
    		puts("T");
    	}
    	
    }


}
int main() {
    int t; cin >> t;
    while(t--) solve();
}