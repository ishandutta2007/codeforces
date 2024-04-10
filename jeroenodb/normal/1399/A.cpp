#include <iostream>


using namespace std;
#define D(a) \
    do { cout << #a " " << (a) << std::endl; } while(false)
int main(){
	int t;
	cin >> t;
	while(t--) {
		int n, a[1002]={};
		cin >> n;
		int mn=1e9,mx=0;
		for(int i=0;i<n;++i) {
			int cur;
			cin >> cur;
			a[cur]++;
			mn = min(mn,cur), mx = max(mx,cur);
		}
		bool can = true;
		for(int i=mn;i<mx;++i) {
			if(a[i]==0) {
				can = false; break;
			}
		}
		if(can) cout << "YES\n";
		else cout << "NO\n";


	}
}