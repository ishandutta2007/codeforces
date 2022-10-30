#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n;
vector<pair<int, int> > ans;
priority_queue<pair<int, int> > q;
pair<int, int> p;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i < n;i++) q.push({i, i});
		ans.clear();
		p = {n, n};
		while(!q.empty()){
			int x = q.top().first, y = q.top().second;q.pop();
			if(1ll * (x - 1) * (x - 1) <= p.first && p.first != 2){
				ans.push_back({p.second, y});
				q.push({(p.first + x - 1) / x, p.second});
				p = {x, y};
			}else{
				ans.push_back({y, p.second});
			}
		}
		printf("%d\n", ans.size());
		for(int i = 0;i < ans.size();i++) printf("%d %d\n", ans[i].first, ans[i].second);
	}
}