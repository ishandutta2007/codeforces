#include <bits/stdc++.h>

#include  <iostream>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		map<string,string>pre;
		map<string,int>hm;
		map<string,string>suf;
		//pre and suf are always 3 characters in length or less
		int ans = 0;
		string waste;
		getline(cin,waste);
		while(n--){
			string ln;
			getline(cin,ln);
			//cerr << ln << " nae lol\n";
			vector<int>spaces;
			for(int i = 0; i<ln.size(); i++){
				if(ln[i]==' '){
					spaces.push_back(i);
				}
			}
			string varname = ln.substr(0,spaces[0]);
			if(spaces.size()==2){
				string s = ln.substr(spaces[1]+1);
				int cnt = 0;
				for(int i = 0; i+3<s.size(); i++){
					if(s.substr(i,4)=="haha")cnt++;
				}
				hm[varname] = cnt;
				pre[varname] = s.substr(0,min(3LL,(int)s.size()));
				suf[varname] = s.substr(max(0LL,s.size()-3LL));
				ans = cnt;
			}
			else{
				string var1 = ln.substr(spaces[1]+1,spaces[2]-spaces[1]-1);
				string var2 = ln.substr(spaces[3]+1);
				int cnt = hm[var1]+hm[var2];
				string s = suf[var1]+pre[var2];
				for(int i = 0; i+3<s.size(); i++){
					if(s.substr(i,4)=="haha")cnt++;
				}
				if(pre[var1].size()<3){
					pre[varname] = s.substr(0,min(3LL,(int)s.size()));
				}
				else{
					pre[varname] = pre[var1];
				}
				if(suf[var2].size()<3){
					suf[varname] = s.substr(max(0LL,s.size()-3LL));
				}
				else{
					suf[varname] = suf[var2];
				}
				hm[varname] = cnt;
				ans = cnt;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}