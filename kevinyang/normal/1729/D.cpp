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
		vector<int>a(n+1);
		for(int i = 1; i<=n; i++){
			cin >> a[i];
		}
		vector<int>b(n+1);
		for(int i = 1; i<=n; i++){
			cin >> b[i];
		}
		vector<int>c(n+1);
		multiset<int>s;
		for(int i = 1; i<=n; i++){
			c[i] = b[i]-a[i];
			s.insert(c[i]);
			//cout << c[i] << " ";
		}
		int ans = 0;
		while(s.size()){
			int v = *s.begin();
			s.erase(s.begin());
			if(s.size()==0)break;
			auto it = s.lower_bound(-v);
			if(it==s.end())continue;
			s.erase(it);
			ans++;
		}
		cout << ans << "\n";
	}
	return 0;
}