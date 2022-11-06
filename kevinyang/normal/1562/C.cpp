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
		cin >> s;
		if(count(s.begin(),s.end(),'0')==0){
			cout << 1 << " " << n-1 << " " << 2 << " " << n << "\n";
			continue;
		}
		bool f = false;
		for(int i = n/2; i<n; i++){
			if(s[i]=='0'){
				cout << 1 << " " <<  i+1 << " " << 1 << " " << i << "\n";
				f = true;
				break;
			}
		}
		if(f)continue;
		for(int i = (n-1)/2; i>=0; i--){
			if(s[i]=='0'){
				cout << i+1 << " " << n << " " << i+2 << " " << n << "\n";
				break;
			}
		}
	}
	return 0;
}