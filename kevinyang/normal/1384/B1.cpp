#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n,k,l;
		cin >> n >> k >> l;
		vector<int>arr(n);
		for(int i = 0; i<n; i++){
			cin >> arr[i];
		}
		/*
		vector<int>changes(max(4*n+1,4*k+1));
		int cur = 0;
		bool up = true;
		for(int i = 1; i<=4*n; i++){
			if(up){
				cur++;
			}
			else{
				cur--;
			}
			if(cur==k){
				up = false;
			}
			if(cur==0){
				up = true;
			}
			changes[i] = cur;
		}
		*/
		vector<int>arr2(n);
		for(int i = 0; i<n; i++){
			arr2[i] = l-arr[i];
		}
		int cur = 0;
		bool decreasing = true;
		bool any = true;
		bool ans = true;
		for(int i = 0; i<n; i++){
			if(arr2[i]<0){
				ans = false;
			}
		}
		if(!ans){
			cout << "NO\n";
			continue;
		}
		for(int i = 0; i<n; i++){
			if(arr2[i]>=k){
				any = true;
				cur = 0;
			}
			else{
				if(any){
					decreasing = true;
					cur = arr2[i];
					any = false;
					if(cur==0){
						decreasing = false;
					}
				}
				else{
					if(decreasing){
						if(cur>arr2[i]){
							cur = arr2[i];
						}
						else{
							
							cur--;
						}
						if(cur==0){
							decreasing = false;
						}
					}
					else{
						if(cur<arr2[i]){
							cur++;
						}
						else{
							ans = false;
							break;
						}
					}
				}
			}
		}
		if(ans){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
		}
	}
	return 0;
}