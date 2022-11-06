#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	vector<char>ans(n+1);
	vector<bool>vis(n+1);
	if(true){
		vector<int>arr(n+1);
		for(int i = 1; i<=n; i++){
			cout << "? 2 1 " << i << endl;
			cin >> arr[i];
		}
		for(int i = 1; i<=n; i++){
			if(arr[i]>arr[i-1]){
				cout << "? 1 " << i << endl;
				cin >> ans[i];
				vis[i] = true;
			}
		}
	}
	for(int i = 1; i<=n; i++){
		if(vis[i])continue;
		vector<int>idx(26);
		for(int j = 1; j<i; j++){
			idx[ans[j]-'a'] = j;
		}
		vector<pair<int,char>>arr;
		for(int i = 0; i<26; i++){
			if(idx[i]){
				arr.push_back({idx[i],(char)('a'+i)});
			}
		}
		sort(arr.begin(),arr.end());
		int low = -1; int high = arr.size(); int mid = (low+high)/2;
		while(low+1<high){
			int l = arr[mid].first;
			cout << "? 2 " << l << " " << i << endl;
			int x;
			cin >> x;
			if(arr.size()-mid==x){
				low = mid;
			}
			else{
				high = mid;
			}
			mid = (low+high)/2;
		}
		ans[i] = arr[low].second;
	}
	cout << "! ";
	for(int i = 1; i<=n; i++){
		cout << ans[i];
	}
	cout << endl;
	return 0;
}