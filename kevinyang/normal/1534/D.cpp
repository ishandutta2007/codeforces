#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	set<pair<int,int>>s;

	queue<int>q;
	q.push(1);
	vector<bool>vis(n+1);
	vis[1] = true;
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		cout << "? " << cur << endl;
		vector<int>dis(n+1);
		for(int i = 1; i<=n; i++){
			cin >> dis[i];
		}
		if(cur==1&&n>=4){
			int cnt = 0;
			for(int i = 1; i<=n; i++){
				if(dis[i]%2==0)cnt++;
			}
			if(cnt>(n+1)/2){
				while(!q.empty())q.pop();
				int val = 0;
				for(int i = 1; i<=n; i++){
					if(dis[i]%2==1){
						val = i;
						break;
					}
				}
				q.push(val); vis[1] = false;
				vis[val] = true;
				continue;
			}
		}
		for(int i = 1; i<=n; i++){
			if(dis[i]==1){
				int x = i; int y = cur;
				if(x>y)swap(x,y);
				s.insert({x,y});
			}
			if(dis[i]==2){
				if(!vis[i]){
					q.push(i);
					vis[i] = true;
				}
			}
		}
	}
	cout << "!" << endl;
	for(pair<int,int>nxt: s){
		cout << nxt.first << " " << nxt.second << endl;
	}
	return 0;
}