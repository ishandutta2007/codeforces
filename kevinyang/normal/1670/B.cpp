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
		s = " " + s;
		int mx = 0;
		int prev = 1;
		int k;
		cin >> k;
		map<int,int>hm;
		for(int i = 0; i<k; i++){
			char ch;
			cin >> ch;
			hm[ch] = 1;
		}
		for(int i = 1; i<=n; i++){
			if(hm[s[i]]){
				if(prev!=0){
					mx = max(mx,i-prev);
				}
				prev = i;
			}
		}
		cout << mx << "\n";
	}
	return 0;
}