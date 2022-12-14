#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		string s; cin >> s;
		vector<int> pos;
		for(int i = 0; i < n; ++i){
			if(s[i] == '*'){
				pos.push_back(i);
			}
		}
		int ans = 0;
		int mid = (int)pos.size() / 2;
		for(int i = 0; i < (int)pos.size(); ++i){
			if(i < mid){
				ans += abs(pos[i] - (pos[mid] - (mid - i)));
			}
			else{
				ans += abs(pos[i] - (pos[mid] + (i - mid)));
			}
		}
		cout << ans << '\n';
	}
	return 0;
}