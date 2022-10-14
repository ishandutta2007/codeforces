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
    	int eights = ((n-1)/4)+1;
    	for(int i=0;i<n-eights;++i) {
    		cout << '9';
    	}
    	for(int i=0;i<eights;++i) cout << '8';
    	cout << endl;
    }
}