#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	vector<vector<int>>adj(26);
	int n;
	cin >> n;
	vector<string>arr(n);
	for(int i = 0; i<n; i++){
		cin >> arr[i];
	}
	for(int i = 0; i<n; i++){
		for(int j = i+1; j<n; j++){
			for(int a = 0; a<min(arr[i].size(),arr[j].size()); a++){
				if(arr[i][a]!=arr[j][a]){
					adj[arr[i][a]-'a'].push_back(arr[j][a]-'a');
					break;
				}
				if(a+1==min(arr[i].size(),arr[j].size())&&arr[i].size()>arr[j].size()){
					cout << "Impossible\n";
					return 0;
				}
			}
		}
	}
	vector<char>ans;
	queue<int>q;
	vector<int>indegrees(26);
	for(int i = 0; i<26; i++){
		for(int nxt: adj[i]){
			indegrees[nxt]++;
		}
	}
	for(int i = 0; i<26; i++){
		if(indegrees[i]==0){
			q.push(i);
		}
	}
	while(q.size()){
		int cur = q.front(); q.pop();
		ans.push_back((char)('a'+cur));
		for(int nxt: adj[cur]){
			indegrees[nxt]--;
			if(indegrees[nxt]==0){
				q.push(nxt);
			}
		}
	}

	if(ans.size()!=26){
		cout << "Impossible\n";
		return 0;
	}
	for(char nxt: ans){
		cout << nxt;
	}
	cout << "\n";
	return 0;
}