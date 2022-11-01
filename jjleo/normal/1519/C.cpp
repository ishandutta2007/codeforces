#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

typedef long long ll;

int t, n;
int u[maxn], s[maxn];
vector<ll> v[maxn]; 
queue<int> q, qq;
ll ans[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%d", &u[i]), v[i].clear(), ans[i] = 0;
		for(int i = 1;i <= n;i++){
			scanf("%d", &s[i]);
			v[u[i]].push_back(s[i]);
		}
		for(int i = 1;i <= n;i++){
			if(v[i].empty()) continue;
			sort(v[i].begin(), v[i].end(), greater<ll>());
			for(int j = 1;j < v[i].size();j++) v[i][j] += v[i][j - 1];
			q.push(i);
		}
		int i = 1;
		while(!q.empty()){
			while(!q.empty()){
				int x = q.front();q.pop();
				ans[i] += v[x][v[x].size() / i * i - 1];
				qq.push(x);
			}
			i++;
			while(!qq.empty()){
				if(v[qq.front()].size() >= i) q.push(qq.front());
				qq.pop();
			}
		}
		for(int i = 1;i <= n;i++) printf("%lld ", ans[i]);puts("");
	}
}