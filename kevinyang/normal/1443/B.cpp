#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int a,b;
		cin >> a >> b;
		string s;
		cin >> s;
		s = "0" + s;
		int start = 1e9;
		int end = 0;
		int count = 0;
		for(int i = 1; i<s.length(); i++){
			if(s[i]=='1'&&s[i-1]=='0'){
				count++;
				end = max(end,i);
				start = min(start,i);
			}
		}
		int total = count*a;
		int cur = 0;
		vector<int>arr;
		for(int i = start; i<=end; i++){
			if(s[i]=='0')cur++;
			if(s[i]=='1'&&cur>0){
				arr.push_back(cur);
				cur = 0;
			}
		}
		sort(arr.begin(),arr.end());
		for(int nxt: arr){
			if(nxt*b<a){
				total-=(a-nxt*b);
			}
		}
		cout << total << "\n";
	}
	return 0;
}