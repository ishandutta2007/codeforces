#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int q;
	cin >> q;
	while(q --){
		string s, t, p;
		cin >> s >> t >> p;
		vector<int> req(26);
		vector<bool> used(t.size());
		int cur = 0;
		bool failed = false;
		for(auto c: s){
			bool found = false;
			for(; cur < t.size(); cur ++){
				if(c == t[cur]){
					found = true;
					used[cur] = true;
					cur ++;
					break;
				}
			}
			if(!found){
				cout << "NO\n";
				failed = true;
				break;
			}
		}
		if(failed){
			continue;
		}
		for(int i = 0; i < t.size(); i ++){
			if(!used[i]){
				req[t[i] - 'a'] ++;
			}
		}
		vector<int> cnt(26);
		for(int i = 0; i < p.size(); i ++){
			cnt[p[i] - 'a'] ++;
		}
		bool pos = true;
		for(int i = 0; i < 26; i ++){
			if(req[i] > cnt[i]){
				pos = false;
				break;
			}
		}
		cout << (pos ? "YES" : "NO") << "\n";
	}
	return 0;
}