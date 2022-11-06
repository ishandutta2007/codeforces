#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	set<int>s;
	for(int i = 1; i<=10000; i++){
		s.insert(i*i*i);
	}
	while(t--){
		int x;
		cin >> x;
		bool f = false;
		for(int nxt: s){
			if(nxt>=x)break;
			if(s.find(x-nxt)!=s.end())f = true;
		}
		if(f)cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}