#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int x;
		cin >> x;
		if(x>45){
			cout << "-1\n";
			continue;
		}
		vector<int>ans;
		for(int i = 9; i>0; i--){
			if(x<=i){
				ans.push_back(x);
				break;
			}
			ans.push_back(i);
			x-=i;
		}
		reverse(ans.begin(),ans.end());
		for(int nxt: ans){
			cout << nxt;
		}
		cout << "\n";
	}
	return 0;
}