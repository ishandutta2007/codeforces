#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int n;
pair<int, int> f[maxn];
map<pair<int, int>, int> mp;
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
bool vis[maxn];
queue<pair<int, int> > q;

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++){
		int x, y;
		scanf("%d%d", &x, &y);
		mp[{x, y}] = i;
	}
	for(auto i : mp){
		int x = i.first.first, y = i.first.second; 
		for(int k = 0;k < 4;k++){
			int xx = x + dx[k], yy = y + dy[k];
			if(mp.find({xx, yy}) == mp.end()){
				vis[i.second] = true;
				f[i.second] = {xx, yy};
				q.push({x, y});
				break;
			}
		}
	}
	while(!q.empty()){
		int x = q.front().first, y = q.front().second;q.pop();
		int i = mp[{x, y}];
		for(int k = 0;k < 4;k++){
			int xx = x + dx[k], yy = y + dy[k];
			if(mp.find({xx, yy}) != mp.end()){
				int j = mp[{xx, yy}];
				if(!vis[j]){
					vis[j] = true;
					f[j] = f[i];
					q.push({xx, yy});
				}
			}
		}
	}
	for(int i = 1;i <= n;i++) printf("%d %d\n", f[i].first, f[i].second);
}