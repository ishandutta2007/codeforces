#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n,x;
		cin >> n >> x;
		multiset<int>s;
		for(int i = 0; i<n; i++){
			int v;
			cin >> v;
			s.insert(v);
		}
		int ans = 0;
		while(s.size()){
			if(s.find(*s.begin()*x)!=s.end()){
				s.erase(s.find(*s.begin()*x));
				s.erase(s.begin());
			}
			else{
				s.erase(s.begin());
				ans++;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}