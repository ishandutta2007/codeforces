#include <bits/stdc++.h>
using namespace std;
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
char freq[2000005];
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int>arr(n+1);
		for(int i = 1; i<=n; i++){
			cin >> arr[i];
			arr[i]+=1e6;
		}
		sort(arr.begin()+1,arr.end());
		bool f = false;
		for(int i = 1; i<=n; i++){
			int cnt = 0;
			for(int j = 1; j<=n; j++){
				if(arr[j]==arr[i]){
					cnt++;
				}
			}
			if(cnt>=n/2)f = true;
		}
		if(f){
			cout << "-1\n";
			continue;
		}
		if(n<=16){
			for(int i = 1; i<=n; i++){
				arr[i-1] = arr[i];
			}
			int ans = 0;
			for(int i = 0; i<(1<<n); i++){
				if(__builtin_popcount(i)<n/2)continue;
				vector<int>vals;
				for(int j = 0; j<n; j++){
					if(i&(1<<j)){
						vals.push_back(arr[j]);
					}
				}
				int v = 0;
				for(int j = 1; j<vals.size(); j++){
					int dif = abs(vals[j]-vals[j-1]);
					v = __gcd(v,dif);
				}
				ans = max(ans,v);
			}
			cout << ans << "\n";
		}
		else{
			int ans = 1;
			
			for(int d = (int)2e6; d>=1; d--){
				bool found = false;
				for(int i = 1; i<=n; i++){
					freq[arr[i]%d]++;
					if(freq[arr[i]%d]==n/2)found = true;
				}
				for(int i = 1; i<=n; i++){
					freq[arr[i]%d]--;
				}
				if(found){
					cout << d << "\n";
					break;
				}
			}
		}
		
	}
	return 0;
}