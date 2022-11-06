#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,c;
	cin >> n >> c;
	vector<int>lens(n+1);
	vector<vector<int>>arr(n+1);
	for(int i = 1; i<=n; i++){
		cin >> lens[i];
		for(int j = 0; j<lens[i]; j++){
			int x;
			cin >> x;
			arr[i].push_back(x);
		}
		arr[i].push_back(0);
	}
	vector<int>psa(c+5);
	for(int i = 1; i<n; i++){
		if(arr[i]==arr[i+1]){
			psa[0]++;
			continue;
		}
		int j = 0;
		for(; j<min((int)arr[i].size(),(int)arr[i+1].size()); j++){
			if(arr[i][j]!=arr[i+1][j])break;
		}
		if(arr[i][j]==0){
			psa[0]++;
		}
		else if(arr[i+1][j]==0){
			cout << "-1\n";
			return 0;
		}
		else if(arr[i][j]<arr[i+1][j]){
			int up = c-arr[i+1][j];
			psa[0]++;
			psa[up+1]--;
			int down = c-(arr[i][j]-1);
			psa[down]++;
		}
		else{
			assert(arr[i][j]>arr[i+1][j]);
			int up = c-arr[i+1][j];
			psa[up+1]--;
			int down = c-(arr[i][j]-1);
			psa[down]++;
		}
		int cur = 0;
	}
	for(int i = 1; i<=c; i++){
		psa[i]+=psa[i-1];
	}
	for(int i = 0; i<c; i++){
		if(psa[i]==n-1){
			cout << i << "\n";
			return 0;
		}
	}
	cout << "-1\n";
	return 0;
}