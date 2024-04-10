#include <iostream>


using namespace std;
#define D(a) \
    do { cout << #a " " << (a) << std::endl; } while(false)
int main(){
	int t;
	cin >> t;
	while(t--) {
		int n, a[51],b[51];
		cin >> n;
		int mna=1e9,mnb=1e9;
		for(int i=0;i<n;++i) {
			cin >> a[i];
			mna = min(mna,a[i]);
		}
		for(int i=0;i<n;++i) {
			cin >> b[i];
			mnb = min(mnb,b[i]);
		}

		long long ans=0;
		for(int i=0;i<n;++i) {
			ans+=max(a[i]-mna,b[i]-mnb);
		}
		cout << ans << endl;


	}
}