#include <bits/stdc++.h>
#define maxn 10

using namespace std;

int n, m;
map<vector<int>, int> f, g;
int a[maxn], b[maxn], c[maxn][maxn];

int main(){
	scanf("%d%d", &n, &m);
	vector<int> v;
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
	for(int i = 1;i <= m;i++) scanf("%d", &b[i]);
	for(int i = 1;i <= n;i++) for(int j = 1;j <= m;j++) scanf("%d", &c[i][j]);
	f[vector<int>(n + 1)] = 0;
	for(int j = 1;j <= m;j++){
		for(map<vector<int>, int>::iterator it = f.begin();it != f.end();++it){
			vector<int> v = it->first;
			v[n] = 0;
			if(g.find(v) == g.end()) g[v] = it->second;
			else g[v] = min(g[v], it->second);
		}
		swap(f, g), g.clear();
		for(int i = 1;i <= n;i++){
			for(map<vector<int>, int>::iterator it = f.begin();it != f.end();++it){
				vector<int> v = it->first; 
				for(int k = 0;k <= min(a[i] - v[i - 1], b[j] - v[n]);k++){
					vector<int> w = v;
					w[i - 1] += k, w[n] += k;	
					if(g.find(w) == g.end()) g[w] = it->second + (k ? c[i][j] : 0);
					else g[w] = min(g[w], it->second + (k ? c[i][j] : 0));			
				}
			}
			swap(f, g), g.clear();
		}
	}
	int ans = 1e9;
	for(map<vector<int>, int>::iterator it = f.begin();it != f.end();++it){
		vector<int> v = it->first; 
		bool tag = false;
		for(int i = 0;i < n;i++){
			if(v[i] < a[i + 1]){
				tag = true;
				break;
			}
		}
		if(!tag) ans = min(ans, it->second);
	}
	printf("%d", ans == 1e9 ? -1 : ans);
}