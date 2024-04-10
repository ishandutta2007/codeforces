#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

const int p = 998244353, pp = 1e9 + 7;

int t, n, m;
int a[maxn], b[maxn];
unsigned long long c[maxn];
vector<int> v[maxn];
//bool vis[maxn];
int deg[maxn];
int f[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		for(int i = 1;i <= n;i++){
			scanf("%d", &a[i]);
			b[i] = c[i] = a[i];
			a[i] %= p;
			b[i] %= pp;
			v[i].clear();
			deg[i] = 0;
		}
		while(m--){
			int x, y;
			scanf("%d%d", &x, &y);
			v[x].push_back(y);
			deg[y]++;
		}
		queue<int> q;
		for(int i = 1;i <= n;i++) if(!deg[i]) q.push(i);
		int cnt = 0;
		while(!q.empty()){
			int x = q.front();q.pop();
			f[++cnt] = x;
			for(auto to : v[x]){
				deg[to]--;
				if(deg[to] == 0) q.push(to);
			}
		}
		int ans = 0;
		for(int i = 1;i < n;i++){
			int x = f[i];
			if(!a[x] && !b[x] && !c[x]) continue;
			for(auto to : v[x]){
				if(!a[to] && !b[to] && !c[to]){
					for(int j = n;j >= i;j--){
						int x = f[j];
						if(!a[x] && !b[x] && !c[x]) continue;
						for(auto to : v[x]){
							a[to] = (a[to] + 1) % p;
							b[to] = (b[to] + 1) % pp;
							c[to]++;
						}
						a[x] = (a[x] + p - 1) % p;
						b[x] = (b[x] + pp - 1) % pp;
						c[x]--;
					}
					ans++;
					break;
				}
			}
			if(!a[x] && !b[x] && !c[x]) continue;
			for(auto to : v[x]){
				a[to] = (a[to] + a[x]) % p;
				b[to] = (b[to] + b[x]) % pp;
				c[to] += c[x];
			}
		}
		printf("%d\n", (a[f[n]] + ans) % p);
	}
}