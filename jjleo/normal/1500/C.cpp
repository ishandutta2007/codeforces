#include <bits/stdc++.h>
#define maxn 1505

using namespace std;

inline int read(){
    int x = 0, f = 1;char ch = getchar();
    while(ch > '9' || ch < '0'){if(ch == '-') f = -1;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch -'0';ch = getchar();}
    return x * f;
}

int n, m;
vector<pair<vector<int>, int> > v[2];
int a[maxn][maxn], b[maxn][maxn], id[maxn];
bitset<maxn> f, g[maxn], h[maxn];
bool vis[maxn];
vector<int> ans;

int main(){
	n = read(), m = read();
	for(int i = 1;i <= n;i++){
		vector<int> w; 
		for(int j = 1;j <= m;j++) a[i][j] = read(), w.push_back(a[i][j]);
		v[0].push_back({w, i});
	}
	for(int i = 1;i <= n;i++){
		vector<int> w; 
		for(int j = 1;j <= m;j++) b[i][j] = read(), w.push_back(b[i][j]);
		v[1].push_back({w, i});
	}
	sort(v[0].begin(), v[0].end()), sort(v[1].begin(),v[1].end());
	for(int i = 0;i < n;i++){
		if(v[0][i].first != v[1][i].first) return printf("-1"), 0;
		id[v[1][i].second] = v[0][i].second;
	} 
	for(int i = 2;i <= n;i++) f[i] = 1;
	for(int j = 1;j <= m;j++){
		for(int i = 2;i <= n;i++){
			g[j][i] = b[i][j] < b[i - 1][j]; 
			h[j][i] = b[i][j] > b[i - 1][j];
		}
	}
	while(1){
		bool tag = false;
		for(int j = 1;j <= m;j++){
			if(vis[j] || (f & g[j]).any()) continue;
			vis[j] = tag = true;
			ans.push_back(j);
			f &= h[j].flip();
		}
		if(!tag) break;
	}
	for(int i = 2;i <= n;i++){
		if(f[i] && id[i] < id[i - 1]) return printf("-1"), 0;
	}
	printf("%d\n", ans.size());
	while(!ans.empty()) printf("%d ", ans.back()), ans.pop_back();
}