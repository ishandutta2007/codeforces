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
		string s;
		cin >> s;
		int cur = s[0];
		vector<int>arr;
		int cnt = 1;
		for(int i = 1; i<n; i++){
			if(s[i]!=cur){
				cur = s[i];
				arr.push_back(cnt);
				cnt = 1;
			}
			else{
				cnt++;
			}
		}
		arr.push_back(cnt);
	 	cur = 0;
	 	int i = 0;
	 	int ans = 0;
	 	while(i<arr.size()){
	 		ans++;
	 		bool f = false;
	 		while(cur<arr.size()){
	 			if(arr[cur]>1){
	 				arr[cur]--;
	 				f = true;
	 				break;
	 			}
	 			else{
	 				cur++;
	 			}
	 		}
	 		if(!f){
	 			arr[i]--;
	 			i++;
	 		}
	 		if(i>=arr.size())break;
	 		arr[i] = 0;
	 		i++;
	 	}
	 	cout << ans << "\n";
	}
	return 0;
}