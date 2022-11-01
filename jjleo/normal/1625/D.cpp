#include <bits/stdc++.h>
#define maxn 300086

using namespace std;

int n, m;
map<int, int> mp;
int x;
int son[maxn * 32][2];
int cnt = 1; 
vector<int> ans;
int val[maxn * 32];
bool ok[maxn * 32];

vector<int> dfs(int i, int dep){
	if(!i) return vector<int>();
	if(dep == -1) return vector<int>(1, val[i]);
	vector<int> l = dfs(son[i][0], dep - 1), r = dfs(son[i][1], dep - 1);
	if(ok[son[i][0]]){
		ok[i] = 1;
		if(!r.empty()) ans.push_back(mp[r[0]]);
		return vector<int>();
	}
	if(ok[son[i][1]]){
		ok[i] = 1;
		if(!l.empty()) ans.push_back(mp[l[0]]);
		return vector<int>();
	}
	bool tag = false;
	if(son[i][1]){
		for(int j = 0;j < l.size();j++){
			int x = (l[j] & ((1 << (dep + 1)) - 1)) ^ (1 << dep);
			int now = son[i][1];
			for(int k = dep - 1;~k;k--){
				if(x & (1 << k)){
					if(son[now][0]) now = son[now][0];
					else now = son[now][1], x ^= 1 << k;
				}else{
					if(son[now][1]) now = son[now][1], x ^= 1 << k;
					else now = son[now][0];
				}
			}
			if(x >= m){
				tag = true;
				ans.push_back(mp[l[j]]), ans.push_back(mp[val[now]]);
				break;
			}
		}
	}	
	if(tag){
		ok[i] = 1;
		return vector<int>();
	}
	l.insert(l.begin(), r.begin(), r.end());
	return l;
}

int main(){
	scanf("%d%d", &n, &m);
	if(m == 0){
		printf("%d\n", n);
		for(int i = 1;i <= n;i++) printf("%d ", i);
		return 0;
	}
	for(int i = 1;i <= n;i++){
		scanf("%d", &x);
		if(mp.find(x) != mp.end()) continue;
		mp[x] = i;
		int now = 1;
		for(int j = 29;~j;j--){
			int k = (x & (1 << j)) != 0;
			if(!son[now][k]) son[now][k] = ++cnt;
			now = son[now][k];
		}
		val[now] = x;
	}
	vector<int> v = dfs(1, 29);
	if(ans.empty()) return printf("-1"), 0;
	if(!v.empty()) ans.push_back(mp[v[0]]);
	printf("%d\n", ans.size());
	for(int i = 0;i < ans.size();i++) printf("%d ", ans[i]);
}
/*
5 1
1 2 3 4 5
*/