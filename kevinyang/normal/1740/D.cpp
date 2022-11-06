#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n,m,k;
		cin >> n >> m >> k;
		vector<int>arr(k+1);
		for(int i = 1; i<=k; i++){
			cin >> arr[i];
		}
		int rem = n*m-3;
		bool f = true;
		set<int>s;
		int cur = 1;
		for(int i = k; i>=1; i--){
			if(s.find(i)!=s.end()){
				s.erase(i);
				continue;
			}
			while(cur<=k){
				s.insert(arr[cur]);
				if(s.size()>rem){
					f = false;
				}
				cur++;
				if(arr[cur-1]==i){
					break;
				}
			}
			s.erase(i);
			if(s.size()>rem){
				f = false;
			}
		}
		if(f){
			cout << "YA\n";
		}
		else{
			cout << "TIDAK\n";
		}
	}
	return 0;
}