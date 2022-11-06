#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int>arr(n+1);
	for(int i = 1; i<n; i++){
		cout << "XOR " << i << " " << i+1 << endl;
		int v;
		cin >> v;
		arr[i+1] = v;
	}
	bool dupe = false;
	set<int>s;
	if(true){
		int cur = 0;
		s.insert(0);
		for(int i = 2; i<=n; i++){
			cur^=arr[i];
			s.insert(cur);
		}
		if(s.size()!=n)dupe = true;
	}
	if(dupe){
		vector<int>pre(n+1);
		for(int i = 1; i<=n; i++){
			pre[i] = pre[i-1]^arr[i];
		}
		int idx = 0;
		int val = 0;
		vector<int>vis(n+1);
		for(int i = 1; i<=n; i++){
			if(vis[pre[i]]){
				cout << "AND " << vis[pre[i]] << " " << i << endl;
				cin >> val;
				idx = i;
				break;
			}
			vis[pre[i]] = i;
		}
		cout << "! ";
		for(int i = 1; i<=n; i++){
			cout << (val^pre[i]^pre[idx]) << " ";
		}
		cout << endl;
		return 0;
	}
	int v1 = 0;
	int v2 = 0;

	if(true){
		int cur = 0;
		for(int i = 2; i<=n; i++){
			cur^=arr[i];
			if(cur==1){
				cout << "AND 1 " << i << endl;
				cin >> v1;
			}
		}
	}
	if(true){
		int cur = 0;
		for(int i = 2; i<=n; i++){
			cur^=arr[i];
			if(cur==2){
				cout << "AND 1 " << i << endl;
				cin >> v2;
			}
		}
	}
	if(v2&1){
		v1^=1;
	}
	int cur = v1;
	cout << "! " << cur << " ";
	for(int i = 2; i<=n; i++){
		cur^=arr[i];
		cout << cur << " ";
	}
	cout << endl;
	return 0;
}