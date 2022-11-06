#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	set<int>s;
	for(int i = 0; i<n; i++){
		int x;
		cin >> x;
		s.insert(x);
	}
	int ans = 0;
	for(int i = 1; i<=100; i++){
		if(s.size()==0)break;
		if(s.find(i)==s.end())continue;
		vector<int>bad;
		for(int nxt: s){
			if(nxt%i==0){
				bad.push_back(nxt);
			}
		}
		if(bad.size()){
			ans++;
			for(int nxt: bad){
				s.erase(nxt);
			}
		}
	}
	cout << ans << "\n";
	return 0;
}