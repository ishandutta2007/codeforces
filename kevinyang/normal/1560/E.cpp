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
		vector<bool>vis(1000);
		vector<char>order;
		int cnt = 0;
		int n = s.length();
		for(int i = n-1; i>=0; i--){
			if(vis[s[i]])continue;
			vis[s[i]] = true;
			order.push_back(s[i]);
			cnt++;
		}
		vector<int>good(n);
		bool f = true;
		int totalgood = 0;
		for(int i = 0; i<cnt; i++){
			int cntl = count(s.begin(),s.end(),order[i]);
			//cout << cntl << " ";
			int freq = count(s.begin(),s.end(),order[i])/(cnt-i);
			if(cntl%(cnt-i)!=0)f = false;

			int cur = 0;
			int val = 0;
			for(int j = 0; j<n; j++){
				if(s[j]==order[i]){
					good[j] = val;
					cur++;
				}
				if(cur==freq){
					val++;
					cur = 0;
				}
			}
			totalgood+=freq;
		}
		string ss = s.substr(0,totalgood);
		vector<vector<int>>ind(26);
		vector<int>curind(26);
		for(int i = 0; i<ss.size(); i++){
			ind[s[i]-'a'].push_back(i);
		}
		int cur = ss.size();
		reverse(order.begin(),order.end());
		//cout << totalgood << " ";
		for(int i = 0; i<n-1; i++){
			if(good[i+1]>=good[i])continue;
			f = false;
		}
		for(int i = 0; i<cnt; i++){
			int v = count(good.begin(),good.end(),i);
			if(v!=cur)f = false;
			cur-=count(ss.begin(),ss.end(),order[i]);
			for(int j = 0; j<26; j++){
				curind[j] = 0;
			}
			if(!f)break;
			vector<int>ord;
			for(int j = 0; j<n; j++){
				if(good[j]==i){
					if(curind[s[j]-'a']>=ind[s[j]-'a'].size()){
						f = false;
						break;
					}
					ord.push_back(ind[s[j]-'a'][curind[s[j]-'a']]);
					curind[s[j]-'a']++;
				}
			}
			for(int i = 0; i<ord.size()-1; i++){
				if(ord[i+1]>=ord[i])continue;
				f = false;
			}
		}
		if(!f){
			cout << "-1\n";
			continue;
		}
		cout << s.substr(0,totalgood) << " ";
		for(char nxt: order){
			cout << nxt;
		}
		cout << "\n";
	}
	return 0;
}