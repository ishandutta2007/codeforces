#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int t;
int n;
int a[2][maxn];
int cnt[maxn];
vector<pair<int, int> > v[maxn];
vector<int> ans;
vector<int> b, c;
bool visp[maxn], vise[maxn];

void dfs(int i){
	bool tag = false;
	visp[i] = true;
	for(int j = 0;j < v[i].size();j++){
		if(vise[abs(v[i][j].second)]) continue;
		tag = true;
		vise[abs(v[i][j].second)] = true;
		if(v[i][j].second > 0) b.push_back(v[i][j].second);
		else c.push_back(-v[i][j].second);
		dfs(v[i][j].first);
	}
	if(!tag){
		if(b.size() > c.size()) swap(b, c);
		for(int i = 0;i < b.size();i++) ans.push_back(b[i]);
		b.clear(), c.clear(); 
	}
} 

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) cnt[i] = 0;
		for(int i = 0;i <= 1;i++){
			for(int j = 1;j <= n;j++){
				scanf("%d", &a[i][j]);
				cnt[a[i][j]]++;
			}
		}
		bool tag = false;
		for(int i = 1;i <= n;i++){
			if(cnt[i] != 2){
				tag = true;
				break;
			}
			v[i].clear();
		}
		if(tag){
			puts("-1");
			continue;
		}
		ans.clear();
		for(int i = 1;i <= n;i++){
			v[a[0][i]].push_back({a[1][i], i});
			v[a[1][i]].push_back({a[0][i], -i});
			visp[i] = vise[i] = false;
		}
		for(int i = 1;i <= n;i++){
			if(!visp[i]) dfs(i);
		}
		printf("%d\n", ans.size());
		for(int i = 0;i < ans.size();i++) printf("%d ", ans[i]);
		puts("");
		
	}
}