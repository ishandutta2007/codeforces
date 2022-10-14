#include <iostream>


using namespace std;
#define D(a) \
    do { cout << #a " " << (a) << std::endl; } while(false)


int main() {
    int t;
    cin >> t;
    while(t--) {
    	int n,m;
    	cin >> n >> m;
    	int acont[1001]={};
    	for(int i=0;i<n;++i) {
    		int cur;
    		cin >> cur;
    		acont[cur]++;
    	}
    	bool ok = false;
    	for(int i=0;i<m;++i) {
    		int cur;
    		 cin >> cur;
    		 if(acont[cur]) {
    		 	if(!ok) {
    		 		cout << "YES" << endl;
	    		 	cout << 1 << ' ' << cur << endl;
	    		 }
    		 	ok = true;

    		 }
    	}
    	if(!ok) cout << "NO" << endl;
    }
}