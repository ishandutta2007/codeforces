#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n, x, y;
int a, b[maxn];
vector<int> v[maxn], c;
priority_queue<pair<int, int> > q;
int ans[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d", &n, &x, &y);
		for(int i = 1;i <= n + 1;i++) v[i].clear();
		for(int i = 1;i <= n;i++){
			scanf("%d", &b[i]);
			v[b[i]].push_back(i);
		}
		while(!q.empty()) q.pop();
		for(int i = 1;i <= n + 1;i++){
			if(v[i].size()) q.push({v[i].size(), i});
			else a = i;
		}
		for(int i = 1;i <= x;i++){
			int j = q.top().second;q.pop();
			ans[v[j].back()] = j;
			v[j].pop_back();
			if(v[j].size()) q.push({v[j].size(), j});
		}
		c.clear();
		while(!q.empty()){
			int i = q.top().second;q.pop();
			for(int j = 0;j < v[i].size();j++) c.push_back(v[i][j]);
		}
		int cnt = 0;
		for(int i = 0;i < c.size();i++){
			if(cnt < y - x && b[c[i]] != b[c[(i + c.size() / 2) % c.size()]]){
				ans[c[i]] = b[c[(i + c.size() / 2) % c.size()]];
				cnt++;
			}else{
				ans[c[i]] = a;
			}
		}
		if(cnt < y - x) puts("NO");
		else{
			puts("YES");
			for(int i = 1;i <= n;i++) printf("%d ", ans[i]);
			puts("");
		}
	}
}