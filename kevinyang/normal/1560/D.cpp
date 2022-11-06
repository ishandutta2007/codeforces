#include <bits/stdc++.h>
using namespace std;
#define int long long
int f(string s, string t){
	swap(s,t);
	int ss = s.size(), ts = t.size();
	int v = 0;
	int cur = 0;
	for(int i = 0; i<ss; i++){
		while(cur<ts&&t[cur]!=s[i]){
			cur++;
		}
		if(cur<ts&&t[cur]==s[i])v++;
		else break;
		cur++;
	}
	return v;
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	//cerr << f("1052","1024");
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int ans = (int)1e9;
		for(int i = 0; i<61; i++){
			string s = to_string((1LL<<i));
			string t = to_string(n);
			int v = f(t,s);
			int val = t.size()+s.size()-v-v;
			ans = min(ans,val);
			//if(t.size()+s.size()-v-v==3)cout << s << "\n";
		}
		cout << ans << "\n";
	}
	return 0;
}