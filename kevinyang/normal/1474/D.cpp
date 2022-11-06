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
		vector<int>arr2(n+5);
		vector<int>arr(n+5);
		for(int i = 1; i<=n; i++){
			cin >> arr[i];
			arr2[i] = arr[i];
		}
		vector<bool>pre(n+5);pre[0] = true;
		vector<int>preans(n+5);
		for(int i = 1; i<=n; i++){
			int mn = min(arr2[i],arr2[i-1]);
			arr2[i-1]-=mn; arr2[i]-=mn;
			if(pre[i-1]&&arr2[i-1]==0){
				pre[i] = true; preans[i] = arr2[i];
			}
		}
		for(int i = 1; i<=n; i++){
			arr2[i] = arr[i];
		}
		vector<bool>suf(n+5);
		vector<int>sufans(n+5);
		suf[n+1] = true;
		for(int i = n; i>0; i--){
			int mn = min(arr2[i],arr2[i+1]);
			arr2[i+1]-=mn; arr2[i]-=mn;
			if(suf[i+1]&&arr2[i+1]==0){
				suf[i] = true; sufans[i] = arr2[i];
			}
		}
		bool f = false;
		if(pre[n]&&preans[n]==0)f = true;
		for(int i = 1; i<n; i++){
			if(pre[i-1]&&suf[i+2]){
				vector<int>a(4); a[0] = preans[i-1]; a[1] = arr[i+1]; a[2] = arr[i]; a[3] = sufans[i+2];
				for(int j = 0; j<3; j++){
					int mn = min(a[j+1],a[j]);
					a[j+1]-=mn; a[j]-=mn;
				}
				if(a[0]+a[1]+a[2]+a[3]==0){
					f = true;
				}
			}
		}
		if(f){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
		}
	}
	return 0;
}