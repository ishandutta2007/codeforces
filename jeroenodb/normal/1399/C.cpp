#include <iostream>


using namespace std;
#define D(a) \
    do { cout << #a " " << (a) << std::endl; } while(false)
int main(){
	int t;
	cin >> t;
	while(t--) {
		int n, a[51]={},b[51]={};
		cin >> n;
		for(int i=0;i<n;++i) {
			int cur;
			cin >> cur;
			a[cur]++;
		}
		int best=0;
		for(int i=2;i<=n*2;++i) {
			for(int j=0;j<=n;++j) b[j]=a[j];
			int ans = 0;
			for(int j=1;j<i;++j) {

				int k = i-j;
				if(j>n or k>n) continue;
				if(j==k) {
					ans+=b[j]/2;
					b[j]-=(b[j]/2) *2;
				} else {
					int tmp = min(b[j],b[k]);
					b[j]-=tmp;b[k]-=tmp;
					ans+=tmp;
				}
			}
			best = max(ans,best);
		}


		cout << best << endl;


	}
}