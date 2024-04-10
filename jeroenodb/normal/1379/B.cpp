#include <iostream>


using namespace std;
#define D(a) \
    do { cout << #a " " << (a) << std::endl; } while(false)


int main() {
    int t;
    cin >> t;
    while(t--) {
    	long long l,r,m;
    	cin >> l >> r >> m;
    	for(int a=l;a<=r;++a) {
    		int bc = m%a;
    		if(a>m) {
    			//cout << "m is small, a doesnt help" << endl;
    			
    			bc = a-m;
    			if(bc <=r-l) {
    				int c=r;
	    			int b = c-bc;
	    			cout << a << ' ' << b << ' ' << c << endl;
	    			break;
    			}
    		    continue;
    		} 
    		if(bc <=r-l) {
    			int b=r;
    			int c = b-bc;
    			cout << a << ' ' << b << ' ' << c << endl;
    			break;

    		}
    		if(a-bc<=r-l) {
    			int c = r;
    			int b = c-(a-bc);
    			cout << a << ' ' << b << ' ' << c << endl;
    			break;
    		}
    	}
    }
}