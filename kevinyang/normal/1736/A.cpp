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
		int ans = 0;
		vector<int>a(n);
		vector<int>b(n);
		for(int i = 0; i<n; i++){
			int x;
			cin >> x;
			a[i] = x;
			ans+=x;
		}
		for(int i = 0; i<n; i++){
			int x;
			cin >> x;
			b[i] = x;
			ans-=x;
		}
		int dif = 0;
		for(int i = 0; i<n; i++){
			dif+=a[i]^b[i];
		}
		cout << min(dif,abs(ans)+1) << '\n';
	}
	return 0;
}