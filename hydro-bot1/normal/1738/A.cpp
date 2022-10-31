// Hydro submission #633c2125d175e25f35b321d0@1664885030274
#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		vector<int> cnt(2);// 
		vector<int> a(n);// 
		for(int i = 0; i < n; i++){
			cin >> a[i];
			cnt[a[i]] += 1; 
		}
		vector<int> b(n);// 
		for(int i = 0; i < n; i++){
			cin >> b[i];
		}
		if(cnt[0] == cnt[1]){// 
			long long ans = 0;
			int mn = b[0];//mn
			for(int i = 0; i < n; i++){
				ans += b[i];//ans
				mn = min(mn, b[i]); 
			} 
			//
			//
			//
			//2
			ans = 2 * ans - mn;
			cout << ans << '\n';
			continue; 
		} 
		if(cnt[1] > cnt[0]){// 
			swap(cnt[1], cnt[0]);//
			// 
			for(int i = 0; i < n; i++){
				a[i] ^= 1;
			} 
		}
		//
		//
		//
		//
		//
		//
		//
		//
		// 
		vector<int> all; 
		long long ans = 0;
		for(int i = 0; i < n; i++){
			ans += b[i];
			if(a[i] == 1){
				ans += b[i];
			}else{
				all.push_back(b[i]);
			}
		}
		sort(all.rbegin(), all.rend());//
		for(int i = 0; i < cnt[1]; i++){
			ans += all[i];
		}
		cout << ans << '\n';
		// 
	}
	return 0;
}