#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	vector<vector<int>>arr(n,vector<int>(m));
	for(int i = 0; i<n; i++){
		for(int j = 0; j<m; j++){
			cin >> arr[i][j];
		}
	}
	bool f = true;
	set<int>mods;
	for(int i = 0; i<m; i++){
		for(int j = i+1; j<m; j++){
			set<int>s2;
			for(int a = 0; a<n; a++){
				s2.insert(arr[a][i]-arr[a][j]);
			}
			if(s2.size()==1){
				int v = *s2.begin();
			}
			else if(s2.size()==2){
				int v = *s2.begin();
				int v2 = *++s2.begin();
				if(v==0||v2==0)f = false;
				if(!(v<0&&v2>0))f = false;
				int mod = abs(v)+abs(v2);
				mods.insert(mod);
			}
			else{
				f = false;
			}
		}
	}
	if(mods.size()>1)f = false;
	if(mods.size()==1){
		int v = *mods.begin();
		for(int i = 0; i<n; i++){
			for(int j = 0; j<m; j++){
				if(arr[i][j]>=v)f = false;
			}
		}
	}
	if(!f){
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
	if(mods.size()==0){
		cout << (int)1e18 << "\n";
		int mn = (int)1e18; int idx = 0;
		for(int i = 0; i<n; i++){
			if(arr[i][0]<mn){
				idx = i;
				mn = arr[i][0];
			}
		}
		vector<int>ans(m);
		for(int j = 0; j<m; j++){
			ans[j] = arr[idx][j];
		}
		vector<int>ans2(n);
		for(int i = 0; i<n; i++){
			ans2[i] = arr[i][0]-arr[idx][0];
		}
		for(int i = 0; i<n; i++){
			cout << ans2[i] << " ";
		}
		cout << "\n";
		for(int j = 0; j<m; j++){
			cout << ans[j] << " ";
		}
		cout << "\n";
	}
	else{
		cout << *mods.begin() << "\n";
		int mod = *mods.begin();
		vector<int>ans(m);
		vector<int>ans2(n);
		for(int j = 0; j<m; j++){
			ans[j] = arr[0][j];
		}
		for(int i = 0; i<n; i++){
			ans2[i] = (arr[i][0]-arr[0][0]+mod)%mod;
		}
		for(int i = 0; i<n; i++){
			cout << ans2[i] << " ";
		}
		cout << "\n";
		for(int j = 0; j<m; j++){
			cout << ans[j] << " ";
		}
		cout << "\n";
	}
	return 0;
}