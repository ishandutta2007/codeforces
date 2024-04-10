#include <iostream>


using namespace std;
#define D(a) \
    do { cout << #a " " << (a) << std::endl; } while(false)


int main() {
    int t;
    cin >> t;
    while(t--) {
    	int n;
    	cin >> n;
    	if(n>=31) {
    		cout << "YES" << endl;
    		int o = n-30;
    		if(o==6 or o==10 or o==14) {
    			cout << "6 10 15 " << n-31 << endl;
    		} else cout << "6 10 14 " << n-30 << endl;
    	} else {
    		cout << "NO" << endl;
    	}
    }
}