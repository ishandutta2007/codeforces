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
		multiset<int>s;
		for(int i = 0; i<n; i++){
			int x;
			cin >> x;
			s.insert(x);
		}
		vector<int>ans;
		for(int i = 0; i<n; i++){
			if(s.find(i)!=s.end()){
				s.erase(s.lower_bound(i));
				ans.push_back(i);
			}
			else{
				break;
			}
		}
		for(int nxt: ans)cout << nxt << " ";
		for(int nxt: s)cout << nxt << " ";
		cout << "\n";
	}
	return 0;
}