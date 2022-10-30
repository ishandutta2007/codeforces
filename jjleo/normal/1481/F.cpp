#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n, m, x, D;
int dep[maxn], tag[maxn];
vector<int> e[maxn];
vector<int> d[maxn];
vector<pair<int, int> > v;
vector<bitset<maxn> > bs; 
int cnt[maxn], ans[maxn];

void dfs(int i){
	d[dep[i]].push_back(i);
	D = max(D, dep[i]);
	for(int j = 0;j < e[i].size();j++){
		int to = e[i][j];
		dep[to] = dep[i] + 1;
		dfs(to);
	}
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 2;i <= n;i++){
		scanf("%d", &x);
		e[x].push_back(i);
		tag[x] = true;
	}
	dfs(1);
	for(int i = 0;i <= D;i++) cnt[d[i].size()]++;
	for(int i = 1;i <= n;i++){
		if(!cnt[i]) continue;
		int x = 1;
		while(cnt[i] - x > 0){
			cnt[i] -= x;
			v.push_back({x * i , i});
			x <<= 1;
		}
		v.push_back({cnt[i] * i, i});
		cnt[i] = 0;
	}
	bitset<maxn> b;
	b.reset(), b[0] = 1;
	bs.push_back(b); 
	for(int i = 0;i < v.size();i++) bs.push_back(bs.back() | (bs.back() << v[i].first));
	if(bs.back()[m]){
		bs.pop_back(), x = m;
		for(int i = v.size() - 1;~i;i--){
			if(x - v[i].first >= 0 && bs.back()[x - v[i].first]){
				cnt[v[i].second] += v[i].first / v[i].second, x -= v[i].first;
			}
			bs.pop_back();
		}
		for(int i = 0;i <= D;i++){
			if(cnt[d[i].size()]){
				cnt[d[i].size()]--;
				for(int j = 0;j < d[i].size();j++) ans[d[i][j]] = 1;
			}
		}
		printf("%d\n", D + 1);
		for(int i = 1;i <= n;i++) printf(ans[i] ? "a" : "b");
		return 0;
	}
	int x = m, y = n - m;
	for(int i = 0;i <= D;i++){
		if(d[i].size() <= x){
			x -= d[i].size();
			for(int j = 0;j < d[i].size();j++) ans[d[i][j]] = 1;
			continue;
		}
		if(d[i].size() <= y){
			y -= d[i].size();
			continue;
		}
		if(x >= y){
			for(int j = 0;j < d[i].size();j++){
				if(tag[d[i][j]]) ans[d[i][j]] = 1, x--;
			}
			for(int j = 0;j < d[i].size() && x;j++){
				if(!tag[d[i][j]]) ans[d[i][j]] = 1, x--;
			}
		}else{
			for(int j = 0;j < d[i].size();j++){
				if(tag[d[i][j]]) ans[d[i][j]] = 1, y--;
			}
			for(int j = 0;j < d[i].size() && y;j++){
				if(!tag[d[i][j]]) ans[d[i][j]] = 1, y--;
			}
			for(int j = 0;j < d[i].size();j++) ans[d[i][j]] ^= 1;
		}
	}
	printf("%d\n", D + 2);
	for(int i = 1;i <= n;i++) printf(ans[i] ? "a" : "b");
}