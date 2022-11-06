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
		string s2;
		cin >> s;
		cin >> s2;
		vector<bool>arr(n);
		vector<bool>arr2(n);
		vector<bool>arr3(n);
		for(int i = 0; i<n; i++){
			arr[i] = s[i]=='1'; arr2[i] = s2[i]=='1';
		}
		vector<int>ans;
		for(int i = n-1; i>=1; i--){
			if(arr[i]==arr2[i])continue;
			if(arr[0]==arr2[i]){
				ans.push_back(1);
			}
			ans.push_back(i+1);
			arr[0] = !arr[0];
			for(int j = 0; j<=i; j++){
				arr3[j] = !arr[i-j];
			}
			for(int j = 0; j<=i; j++){
				arr[j] = arr3[j];
			}
		}
		if(arr[0]!=arr2[0])ans.push_back(1);
		cout << ans.size() << " ";
		for(int nxt:ans){
			cout << nxt << " ";
		}
		cout << "\n";
	}
	return 0;
}