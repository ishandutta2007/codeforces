#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		int x;
		cin >> x;
		int n = s.length();
		vector<int>arr(n);
		for(int i = 0; i<n; i++){
			arr[i] = 1;
		}
		for(int i = 0; i<n; i++){
			if(s[i]=='0'){
				if(i-x>=0){
					arr[i-x] = 0;
				}
				if(i+x<n){
					arr[i+x] = 0;
				}
			}
		}
		bool f = true;
		for(int i = 0; i<n; i++){
			if(s[i]=='1'){
				bool f2 = false;
				if(i-x>=0){
					if(arr[i-x]==1)f2 = true;
				}
				if(i+x<n){
					if(arr[i+x]==1)f2 = true;
				}
				if(!f2){
					f = false;
				}
			}
		}
		if(f){
			for(int i = 0; i<n; i++){
				cout << arr[i];
			}
			cout <<"\n";
		}
		else{
			cout << "-1\n";
		}
	}
	return 0;
}