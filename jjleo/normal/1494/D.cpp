#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n;
vector<pair<int, int> > v[maxn]; 
int x;
int fa[maxn];
vector<pair<int, int> > ans;
int a[maxn], A[505][505];

int find(int x){
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}


int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++){
		fa[i] = i;
		for(int j = 1;j <= n;j++){
			scanf("%d", &x), A[i][j] = x;
			if(i == j) a[i] = x;
			if(i <= j) continue;
			v[x].push_back({i, j});
		}
	}
	for(int i = 1;i <= 5000;i++){
		if(v[i].empty()) continue;
		int m = n;
		vector<int> w; 
		for(int j = 0;j < v[i].size();j++){
			w.push_back(v[i][j].first), w.push_back(v[i][j].second);
		}
		sort(w.begin(), w.end());
		w.erase(unique(w.begin(), w.end()), w.end());
		for(int k = 0;k < w.size();k++){
			for(int l = 0;l < k;l++){
				if(A[w[k]][w[l]] == i){
					int x = find(w[k]), y = find(w[l]);
					if(x == y) continue;
					if(x <= m && y <= m){
						a[++n] = i, fa[n] = n;
						fa[x] = n, ans.push_back({x, n}), x = n;
					}
					if(x < y) swap(x, y);
					fa[y] = x, ans.push_back({y, x});
				}
			}
		}
	}
	printf("%d\n", n);
	for(int i = 1;i <= n;i++) printf("%d ", a[i]);
	printf("\n%d\n", n);
	for(int i = 0;i < ans.size();i++) printf("%d %d\n", ans[i].first, ans[i].second);
}