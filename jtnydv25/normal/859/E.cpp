#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sd(x) scanf("%d", &(x))
#define pb push_back

const int N = 2e5 + 120, mod = 1e9 + 7;

int sink[N], nxt[N], vis[N], cnt[N], valid[N];
vector<int> ulta[N];
set<int> st;
int main(){
	int n, u, v;
	sd(n);
	for(int i = 1; i <= n; i++){
		sd(u); sd(v);
		nxt[u] = v;
		ulta[v].pb(u);
		valid[u] = 1;
		valid[v] = 1;
	}
	int cycles = 0;
	int ans = 1;
	for(int i = 1; i <= 2 * n; i++){
		if(!valid[i]) continue;
		if(!vis[i]){
			// cerr << "node = " << i << endl;
			int u = i;
			st.clear();
			st.insert(u);
			if(nxt[u] == u){
				continue;
			}
			if(!nxt[u]){
				sink[u] = u;
				vis[u] = 1;
				continue;
			}
			u = nxt[u];
			int snk, type, val;
			while(1){
				if(nxt[u] == u){
					type = 4;
					break;
				}
				if(vis[u]){
					val = u;
					type = 3;
					break;
				}
				if(st.count(u)){
					type = 1;
					break;
				}
				if(!nxt[u]){
					type = 2;
					snk = u;
					break;
				}
				st.insert(u);
				u = nxt[u];
			}
			if(type == 4){
				for(int x : st) vis[x] = 1;
				continue;
			}
			if(type == 1){
				cycles++;
				ans = (ans * 2) % mod;
				for(int x : st) vis[x] = 1;
				continue;
			}
			if(type == 2){
				for(int x : st) sink[x] = snk, vis[x] = 1;
				continue;
			}
			for(int x : st){
				sink[x] = sink[val];
				vis[x] = 1;
				continue;
			}
		}
	}


	for(int i = 1; i <= 2 * n; i++){
		cnt[sink[i]]++;
	}

	for(int i = 1; i <= 2 * n; i++){
		if(cnt[i])
		ans = (ans * 1ll * (cnt[i])) % mod;
	}

	printf("%d\n", ans);
	
}