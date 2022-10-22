#include <bits/stdc++.h>
using namespace std;
#define int long long
bool f(char c){
	if(c == 'a' || c == 'e' || c == 'u' || c == 'i' || c == 'o'){
		return true;
	}
	return false;
}
bool cmp(pair<string ,char> c, pair<string ,char> c1){
	if(c.second > c1.second){
		return true;
	}
	return false;
}
signed main() {
	int n;
	cin >> n;
	vector<vector<pair<string, char>>> a(100001);
	for(int i = 0;i < n;i++){
		string s;
		cin >> s;
		int k = 0;
		char c;
		for(int j = 0;j  < s.size();j++){
			if(f(s[j])){
				k++;
				c = s[j];
			}
		}
		a[k].push_back({s, c});
	}
	vector<pair<string,string>> ans1, ans2, ans;
	for(int i = 0;i < a.size();i++){
		if(a[i].size() > 1){
			sort(a[i].begin(),a[i].end(), cmp);
			vector<bool> used(a[i].size(),false);
			for(int u = 0;u < a[i].size();u++){
				if(u < a[i].size() - 1){
					if(a[i][u].second == a[i][u + 1].second){
						ans1.push_back({a[i][u].first, a[i][u + 1].first});
					    used[u] = true;
					    used[u + 1] = true;
					    u += 1;
					}
				}
			}
			int j = -1;
			for(int u = 0;u < a[i].size();u++){
				if(used[u] == false){
					if(j == -1){
						j = u;
					}
					else{
						ans2.push_back({a[i][j].first, a[i][u].first});
						j = -1;
					}
				}
			}
		}
	}
	int i = 0, u =0;
	while(i < ans1.size()){
		if(u >= ans2.size()){
			if(i < ans1.size() - 1){
				ans.push_back(ans1[i]);
				ans.push_back(ans1[i + 1]);
				i += 2;
			}
			else{
				i++;
			}
		}
		else{
			ans.push_back(ans1[i]);
			ans.push_back(ans2[u]);
			i++;
			u++;
		}
	}
	cout << ans.size() / 2 << endl;
	for(int i =0;i < ans.size();i+= 2){
		cout << ans[i + 1].first << " " << ans[i].first << endl;
		cout << ans[i + 1].second << " " << ans[i].second << endl;
	}
	
}