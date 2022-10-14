#include <iostream>


using namespace std;
#define D(a) \
    do { cout << #a " " << (a) << std::endl; } while(false)
const int mxN = 1e5;

int main() {
    int t;
    cin >> t;
    while(t--) {
    	int n;
    	cin >> n;
    	int piles[mxN];
    	for(int i=0;i < n;++i) cin >> piles[i];
    	bool firstcontrol = false, allones = true;
    	for(int i=0;i<n;++i) {
    		if(piles[i]!=1) {
    			allones = false;
    			firstcontrol = i%2==0;
    			break;
    		}
    	}
    	if((allones and n%2==1) or firstcontrol) {
    		cout << "First" << endl;
    	} else cout << "Second" << endl;
    }
}