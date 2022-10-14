#include <iostream>


using namespace std;
#define D(a) \
    do { cout << #a " " << (a) << std::endl; } while(false)


int main() {
    int t;
    cin >> t;
    while(t--) {
    	int n,k,z, a[100000], prefixsum[100001];
    	cin >> n >> k >> z;
    	prefixsum[0]=0;
    	for(int i=0;i<n;++i) {
    		cin >> a[i];
    		prefixsum[i]+=a[i];
    		prefixsum[i+1]=prefixsum[i];

    	}
    	int best = prefixsum[k];
    	//cout << "just rightwalking = " << best << endl;
    	for(int i=0;i<n-1;++i) {
    		int left = k-i;
    		if(left<2) break;
    		int cur = 0;
    		int toa;
    		if(z*2>=left) {
    			cur+=left/2 *(a[i]+a[i+1]);
    			toa=i+(left&1);
    		} else {
    			cur+=z*(a[i]+a[i+1]);
    			toa = i+left-2*z;
    		}
    		cur+=prefixsum[toa];
    		//cout << "tried repeating at " << i << endl;
    		//cout << "score = " << cur << endl;
    		best = max(cur,best);

    	}
    	cout << best << endl;

    }
}