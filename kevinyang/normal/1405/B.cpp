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
		vector<int>arr(n);
		int total = 0;
		for(int i = 0; i<n; i++){
			cin >> arr[i];
			if(arr[i]>0)total+=arr[i];
		}
		int pos = 0;
		int neg = 1;
		while(neg<n&&pos<n){
			if(pos>=neg){
				neg++;
				continue;
			}
			if(arr[pos]>0){
				if(arr[neg]<0){
					int mn = min(arr[pos],abs(arr[neg]));
					arr[neg]+=mn;
					total-=mn;
					arr[pos]-=mn;
				}
				else{
					neg++;
				}
			}	
			else{
				pos++;
			}
		}
		cout << total << "\n";
	}
	return 0;
}