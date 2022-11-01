#include <bits/stdc++.h>
#define maxn 1000086

using namespace std;

typedef long long ll;

const int p = 1e9 + 7;

int n, m;
int f[100][10];

int g[maxn][6], cnt = 1, c;
int son[maxn][2];
char s[100];
vector<int> v;

inline void up(int x, int i){
	if(i == 1){
		for(int j = 0;j < 6;j++) g[x][j] = 1;
		return;
	}
	for(int j = 0;j < 6;j++){
		g[x][j] = 0;
		for(int k = 0;k < 6;k++) if(!(j == k || (j ^ k) == 1)){
			for(int l = 0;l < 6;l++) if(!(j == l || (j ^ l) == 1)){
				g[x][j] = (g[x][j] + 1ll * (son[x][0] ? g[son[x][0]][k] : f[i - 1][k]) * (son[x][1] ? g[son[x][1]][l] : f[i - 1][l])) % p;
			}
		}
	}
}

void modify(int x, int dep){
	if(v.empty()){
		up(x, dep);
		for(int i = 0;i < 6;i++) if(i ^ c) g[x][i] = 0;
		return;
	}
	int id = v.back();v.pop_back();
	if(!son[x][id]) son[x][id] = ++cnt;
	modify(son[x][id], dep - 1);
	up(x, dep);
}

int main(){
	scanf("%d", &n);
	for(int i = 0;i < 6;i++) f[1][i] = 1;
	for(int i = 2;i <= n;i++){
		for(int j = 0;j < 6;j++){
			for(int k = 0;k < 6;k++) if(!(j == k || (j ^ k) == 1)){
				for(int l = 0;l < 6;l++) if(!(j == l || (j ^ l) == 1)){
					f[i][j] = (f[i][j] + 1ll * f[i - 1][k] * f[i - 1][l]) % p;
				}
			}
		}
	}
	scanf("%d", &m);
	vector<pair<ll, int> > w;
	while(m--){
		ll x;
		scanf("%lld%s", &x, s);
		if(s[0] == 'w') c = 0;
		else if(s[0] == 'y') c = 1;
		else if(s[0] == 'g') c = 2;
		else if(s[0] == 'b') c = 3;
		else if(s[0] == 'r') c = 4;
		else c = 5;
		w.push_back({x, c});
	}
	sort(w.begin(), w.end(), greater<pair<ll, int> >());
	for(int i = 0;i < w.size();i++){
		ll x = w[i].first;
		c = w[i].second;
		while(x > 1) v.push_back(x & 1), x >>= 1;
		modify(1, n);
	}
	int ans = 0;
	for(int i = 0;i < 6;i++) ans = (ans + g[1][i]) % p;
	printf("%d", ans); 
}