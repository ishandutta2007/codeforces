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
		set<int>cand;
		if(true){
			cout << "? 2 1 " << n << " 1" << endl;
			int x;
			cin >> x;
			if(x<=2){
				cand.insert(1); cand.insert(n);
			}
		}
		for(int i = 1; i<n; i+=2){
			cout << "? 2 " << i << " " << i+1 << " 1" << endl;
			int x;
			cin >> x;
			if(x<=2){
				cand.insert(i); cand.insert(i+1);
			}
		}
		vector<int>ans(n+1);
		int low = 0;
		if(cand.size()==1){
			low = *cand.begin(); 
			ans[low] = 1;
		}
		else{
			int v = *cand.begin(); cand.erase(v);
			while(cand.size()){
				int cur = *cand.begin(); cand.erase(cur);
				cout << "? 2 " << v << " " << cur << " 1" << endl;
				int x;
				cin >> x;
				if(x==1)low = v;
				cout << "? 2 " << cur << " " << v << " 1" << endl;
				cin >> x;
				if(x==1)low = cur;
			}
			ans[low] = 1;
		}
		for(int i = 1; i<=n; i++){
			if(i==low)continue;
			cout << "? 1 " <<  low << " " << i << " " << n-1 << endl;
			int x;
			cin >> x;
			ans[i] = x;
		}
		cout << "! ";
		for(int i = 1; i<=n; i++){
			cout << ans[i] << " ";
		}
		cout << endl;
	}
	return 0;
}