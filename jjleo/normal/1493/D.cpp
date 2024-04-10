#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

const int p = 1e9 + 7;

inline int fpow(int x, int y){
	int ans = 1;
	while(y){
		if(y & 1) ans = 1ll * ans * x % p;
		x = 1ll * x * x % p, y >>= 1; 
	}
	return ans;
}

int n, q;
multiset<int> st[maxn]; 
map<int, int> mp[maxn];
int prm[maxn], cnt, f[maxn];
int x, y; 
int ans = 1;

int main(){
	scanf("%d%d", &n, &q);
	for(int i = 2;i < maxn;i++){
		if(!f[i]) f[i] = i, prm[++cnt] = i;
		for(int j = 1;j <= cnt && prm[j] * i < maxn;j++){
			f[prm[j] * i] = prm[j];
			if(i % prm[j] == 0) break;
		}
	}
	for(int i = 1;i <= n;i++){
		scanf("%d", &x);
		while(x ^ 1){
			mp[i][f[x]]++;
			x /= f[x];
		}
	}
	for(int i = 1;i <= n;i++){
		for(map<int, int>::iterator it = mp[i].begin();it != mp[i].end();++it){
			st[it->first].insert(it->second);
		}
	}
	for(int i = 1;i <= cnt;i++) ans = 1ll * ans * fpow(prm[i], st[prm[i]].size() < n ? 0 : *st[prm[i]].begin()) % p;
	while(q--){
		scanf("%d%d", &x, &y);
		while(y ^ 1){
			int i = st[f[y]].size() < n ? 0 : *st[f[y]].begin();
			if(mp[x].find(f[y]) != mp[x].end()) st[f[y]].erase(st[f[y]].find(mp[x][f[y]]));
			st[f[y]].insert(++mp[x][f[y]]);
			ans = 1ll * ans * fpow(f[y], (st[f[y]].size() < n ? 0 : *st[f[y]].begin()) - i) % p;
			y /= f[y];
		}
		printf("%d\n", ans);
	}
}