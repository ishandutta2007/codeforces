#include <bits/stdc++.h>
#define maxn 2086

using namespace std;

typedef long long ll;

int n, m, w;
int a[maxn][maxn];

inline int id(int x, int y){
	return (x - 1) * m + y;
}

vector<int> v[maxn * maxn];

inline void addEdge(int x, int y){
	v[x].push_back(y), v[y].push_back(x);
}

queue<int> q;
int d[maxn * maxn];//

inline ll read(){
    ll x = 0, f = 1;char ch = getchar();
    while(ch > '9' || ch < '0'){if(ch == '-') f = -1;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch -'0';ch = getchar();}
    return x * f;
}

int main(){
	n = read(), m = read(), w = read();
	for(int i = 1;i <= n;i++) for(int j = 1;j <= m;j++) a[i][j] = read();
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			if(a[i][j] == -1) continue;
			if(i - 1 > 0 && a[i - 1][j] != -1) addEdge(id(i, j), id(i - 1, j));
			if(j - 1 > 0 && a[i][j - 1] != -1) addEdge(id(i, j), id(i, j - 1));
		}
	}
	memset(d, 0x3f, sizeof(d));
	d[id(1, 1)] = 0, q.push(id(1, 1));
	ll ans = 1e18, sum1 = 1e18, sum2 = 1e18;
	while(!q.empty()){
		int x = (q.front() - 1) / m + 1, y = (q.front() - 1) % m + 1;q.pop();
		if(x == n && y == m) ans = min(ans, 1ll * d[id(x, y)] * w);
		if(a[x][y]) sum1 = min(sum1, 1ll * w * d[id(x, y)] + a[x][y]);
		x = id(x, y);
		for(int i = 0;i < v[x].size();i++){
			int to = v[x][i];
			if(d[to] > d[x] + 1){
				d[to] = d[x] + 1;
				q.push(to);
			}
		}
	}
	memset(d, 0x3f, sizeof(d));
	d[id(n, m)] = 0, q.push(id(n, m));
	while(!q.empty()){
		int x = (q.front() - 1) / m + 1, y = (q.front() - 1) % m + 1;q.pop();
		if(a[x][y]) sum2 = min(sum2, 1ll * w * d[id(x, y)] + a[x][y]);
		x = id(x, y);
		for(int i = 0;i < v[x].size();i++){
			int to = v[x][i];
			if(d[to] > d[x] + 1){
				d[to] = d[x] + 1;
				q.push(to);
			}
		}
	}
	ans = min(ans, sum1 + sum2);
	printf("%lld", ans == 1e18 ? -1 : ans);
}