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
		vector<int>degrees(n+1,-1);
		vector<int>val(n+1);
		for(int i = 1; i<=n; i++){
			cin >> val[i];
		}
		for(int i = 0; i<n-1; i++){
			int x,y;
			cin >> x >> y;
			degrees[x]++; degrees[y]++;
		}
		multiset<int>s;
		int ans = 0;
		for(int i = 1; i<=n; i++){
			ans+=val[i];
		}
		for(int i = 1; i<=n; i++){
			for(int j = 0; j<degrees[i]; j++){
				s.insert(val[i]);
			}
		}
		cout << ans << " ";
		while(s.size()>0){
			int val = *(--s.end());
			s.erase(s.lower_bound(val));
			ans+=val;
			cout << ans << " ";
		}
		cout << "\n";
	}
	return 0;
}