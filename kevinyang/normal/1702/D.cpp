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
		int p;
		cin >> p;
		string s2 = s;
		sort(s2.begin(),s2.end());
		int sum = 0;
		for(char nxt: s){
			sum+=nxt-'a'+1;
		}
		vector<int>a(26);
		while(sum>p){
			sum-=(s2.back()-'a'+1);
			a[s2.back()-'a']++;
			s2.pop_back();
			
		}
		for(char nxt: s){
			if(a[nxt-'a']==0)cout << nxt;
			else a[nxt-'a']--;
		}
		cout << "\n";
	}
	return 0;
}