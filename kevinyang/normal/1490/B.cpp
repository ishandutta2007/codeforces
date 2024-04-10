#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int>a(3);
		for(int i = 0; i<n; i++){
			int x;
			cin >> x;
			x%=3;
			a[x]++;
		}
		int ans = 0;
		int v = n/3;
		for(int i = 0; i<3; i++){
			if(a[i]>v){
				a[(i+1)%3]+=a[i]-v;
				ans+=a[i]-v;
				a[i] = v;
			}
		}
		for(int i = 0; i<3; i++){
			if(a[i]>v){
				a[(i+1)%3]+=a[i]-v;
				ans+=a[i]-v;
				a[i] = v;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}